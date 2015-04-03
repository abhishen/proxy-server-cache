#RPC Proxy Server-Client Cache

Platform
Ubuntu 14.04.1 LTS

To compile all the code:
	make all

To run the programs:

Cachesizes varied as 1MB, 3MB, 5MB
Workloads: workloada.txt workloadb.txt workloadc.txt

Server:
	./Proxy_server_lru <cache-size>
	./Proxy_server_random <cache-size>
	./Proxy_server_fifo <cache-size>

Client:
	./Proxy_client <workload>

Latency will be printed on client side
Cache hits/misses will be printed on server side
