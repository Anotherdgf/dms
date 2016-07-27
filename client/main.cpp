#include <iostream>
#include "logReader.h"
#include "socketSender.h"
#include "consoleSender.h"
#include "client.h"
#include <cstdlib>
#include <cstring>

/*
   客户端应用程序入口函数
 */
int main(int argc,char* argv[])
{
	try
	{
		// 重置测试日志文件
		string cmd("./reset.sh");
		system(cmd.c_str());

		//初始化日志文件的读取器
		LogReader reader("./wtmpx","logins.dat");

		//日志发送"
		SocketSender sender("127.0.0.1",8888,"./fail.dat");

		Client client(reader,sender);

		client.dataMine();

	}
	catch(ClientException ex)
	{
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}

