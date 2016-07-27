#include "server.h" 
//构造函数
Server::Server(LogDao& dao,const string& ip,short port)throw(ServerException)
	:m_store(dao),m_socket(ip,port){};
		
		
//数据采集函数
void Server::dataMine(void) throw(ServerException)
{
	try
	{
		//1.启动存储线程准备存储数据
		m_store.start();

		//2.启动客户端线程等待连接
		m_socket.acceptClient();
	}
	catch(ServerException)
	{
		throw;//继续抛出异常
	}
}
