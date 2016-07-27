#ifndef CLIENTTHREAD_H__
#define CLIENTTHREAD_H__
#include "logThread.h"


class ClientThread: public LogThread
{
	private:
		int m_connfd;//客户端套接节
	public:
		ClientThread(int connfd);
		//虚函数覆盖版本
		void run(void) throw (ThreadException);
};
#endif
