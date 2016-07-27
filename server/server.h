#ifndef __SERVER_H__
#define __SERVER_H__
#include "storeThread.h"
#include "serverSocket.h"
#include "logDao.h"
using namespace std;
class Server
{
	private:
		StoreThread m_store;//存储线程
		ServerSocket m_socket;//服务器套节字
	public:
		Server(LogDao& dao,const string& ip,short port)throw(ServerException);
		//数据采集函数
		void dataMine(void) throw(ServerException);
};
#endif
