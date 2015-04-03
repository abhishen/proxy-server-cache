// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Proxy.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <curl/curl.h>
#include <time.h>
#include <queue>
#include <map>
//#define CACHESIZE 1024000

using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::rpc;
long cacheSize, sizeOfCache;

class ProxyHandler : virtual public ProxyIf {

private:
	std::map <int, string> cacheEntries; //Used for Random
	std::map <string, string> cache; //Actual cache of web-document
	long maxsize;
	int32_t count = 0;
	int32_t cacheHits = 0;
	int32_t cacheMisses = 0;
public:
	ProxyHandler() {
    // Your initialization goes here
  	}	

 	static size_t writebuf(void *buffer, size_t size, size_t nmemb, void *userp){
  		((string*)userp)->append((char*)buffer, size * nmemb);
  		return size*nmemb;
  	}

  	int32_t ping() {
    	// Your implementation goes here
    	printf("ping\n");
  	}

	int32_t currentTime() {
    	printf("currentTime\n");
		time_t t = time(0);
    	struct tm * now = localtime(&t);
    	cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << endl;
  	}

	long getCurrentSize() {
		long currentSize = cacheSize - maxsize;
		return currentSize;
	}

	void addCacheEntry (long entry) {
		maxsize = maxsize + entry;
	}

	void randomEviction() {
		int start, end , index;
		
		// Check if <int, string> map has this entry. If not, which means this entry is already deleted loop until proper index is found
		std::map<int, string>::iterator it = cacheEntries.begin();
		start = it->first;
		end = count;
		while(1) {
			srand(time(NULL));
			index = rand() % end + start;
			it = cacheEntries.find(index);
			if(it != cacheEntries.end())
				break;
		}
		maxsize = maxsize - cache[cacheEntries[index]].size();
		cache.erase(cacheEntries[index]);
		cacheEntries.erase(index);
		return;
	}
		

  	void getURL(std::string& _return, const std::string& url) {
    	// Your implementation goes here
		string out;
		//Look for url in cache
 		std::map<string, string>::iterator it;
		it = cache.find(url);
		//If not found
		if (it == cache.end()) {
			printf("------CACHE MISS-----\n");
			cacheMisses++;
			CURL *curl = curl_easy_init();
			if(curl) {
        		CURLcode res;
        		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
				curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writebuf);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
       	 		res = curl_easy_perform(curl);
       			curl_easy_cleanup(curl);
				_return = out.c_str();	
				if(out.size() > sizeOfCache) {
					printf("Size exceeded!\n");
				} else {
				// If cache has space
				if(getCurrentSize() >= out.size()) {
					cache.insert(std::pair<string,string>(url,out.c_str()));
					//Maintain index
					cacheEntries.insert(std::pair<int, string>(count,url));
					count++;
					//Make changes in size available
					addCacheEntry(cache[url].size());

				// If no space in cache
				} else {
					//Evict random entry
					while(1) {
						if(out.size() > getCurrentSize()) {
							printf("Evict!\n");
							randomEviction();
				//If there is space in cache
						} else if(getCurrentSize()>=out.size()) {
							cache.insert(std::pair<string,string>(url,out.c_str()));
							cacheEntries.insert(std::pair<int, string>(count,url));
							count++;
							//Make changes in size available							
							addCacheEntry(cache[url].size());
							break;
						}
					}
				}
			} 
		} else {
        		printf("Could not get cURL handle!\n");
        		exit(EXIT_FAILURE);
			}
		//If found
		} else {
			cacheHits++;
			_return = cache[url.c_str()];
			printf("------CACHE HIT-----\n");
		}
	printf("Cache hits: %d\n", cacheHits);
	printf("Cache misses: %d\n", cacheMisses);
	}

};

int main(int argc, char **argv) {	
	if(argc == 2) {
		cacheSize = atol(argv[1]);
	} else {
		cacheSize = 1024000;
	}
	sizeOfCache = cacheSize;
	int port = 9146;
  	shared_ptr<ProxyHandler> handler(new ProxyHandler());
  	shared_ptr<TProcessor> processor(new ProxyProcessor(handler));
  	shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  	shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  	TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  	server.serve();
  	return 0;
}
