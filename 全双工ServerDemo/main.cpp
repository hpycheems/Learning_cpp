#include "CSession.h"
#include "CServer.h"

#include <iostream>
#define Test 10

/*
*  ǰ���ͨ�� json
*  ������֮��ͨ�� protobuf
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