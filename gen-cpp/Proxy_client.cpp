#include "Proxy.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <curl/curl.h>
#include <fstream>
#include <time.h>

using namespace std;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace rpc;

int main(int argc, char **argv) {
	boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9146));
  	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  	string op;
  	struct timeval startTime, endTime;
  	double total = 0;
	string line;
  	ifstream filename (argv[1]);
  	ProxyClient client(protocol);
  	transport->open();
  	client.ping();
  	client.currentTime();
  	int count = 0;
  	if(filename.is_open()) {
  		while ( getline(filename, line)) {
			count++;
			gettimeofday(&startTime, NULL);
			client.getURL(op,line);
			gettimeofday(&endTime, NULL);
			total += ((endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec)/1000000.0));
		}

		if(count == 0)
			printf("No URL in the file.\n");
		else
			printf("Average Latency: %f seconds\n", (total/count*1.0));
		filename.close();
	} else {
		printf("Can't open file!\n");
	}

	transport->close();
	return 0;
}
