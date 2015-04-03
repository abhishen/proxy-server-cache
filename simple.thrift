#!/usr/local/bin/thrift --gen cpp

namespace cpp rpc

service Proxy {
	i32 ping()
	i32 currentTime()
	string getURL(string url)
}
