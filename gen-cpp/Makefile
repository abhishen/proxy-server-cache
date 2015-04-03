server_lru:
	g++ -Wall -I/usr/local/include/thrift -c Proxy.cpp -o proxy.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c Proxy_server_lru.cpp -o server.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c simple_constants.cpp -o constants.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c simple_types.cpp -o types.o -lcurl	
	g++ -L/usr/local/lib *.o -o Proxy_server_lru -lthrift -lcurl

server_fifo:
	g++ -Wall -I/usr/local/include/thrift -c Proxy.cpp -o proxy.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c Proxy_server_fifo.cpp -o server.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c simple_constants.cpp -o constants.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c simple_types.cpp -o types.o -lcurl	
	g++ -L/usr/local/lib *.o -o Proxy_server_fifo -lthrift -lcurl

server_random:
	g++ -Wall -I/usr/local/include/thrift -c Proxy.cpp -o proxy.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c Proxy_server_random.cpp -o server.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c simple_constants.cpp -o constants.o -lcurl
	g++ -Wall -I/usr/local/include/thrift -c simple_types.cpp -o types.o -lcurl	
	g++ -L/usr/local/lib *.o -o Proxy_server_random -lthrift -lcurl

client:
	g++ -Wall -I/usr/local/include/thrift -c Proxy_client.cpp -o client.o -lcurl
	g++ -L/usr/local/lib client.o proxy.o constants.o types.o -o Proxy_client -lthrift -lcurl

all: server_lru server_fifo server_random client

clean:
	$(RM) *.o server client
