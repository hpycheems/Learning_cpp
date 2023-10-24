#include "CSession.h"
#include "CServer.h"

#include <iostream>
#define Test 10

/*
*  前后端通信 json
*  服务器之间通信 protobuf
*/

int main(){

	try
	{
		boost::asio::io_context io;

		CServer server(io, 8888);

		io.run();
	}
	catch (const std::exception&)
	{

	}

	return 0;
}