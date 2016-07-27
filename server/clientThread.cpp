
#include "clientThread.h"
#include "logBuffer.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

/*
   private:
   int m_connfd;//客户端socket套节字
 */

//构造函数
ClientThread::ClientThread(int connfd):m_connfd(connfd){}

void ClientThread::run(void)throw(ThreadException){
	//不断将收到客户端的数据放入缓冲区中
	MLogRec log;
	unsigned long long logs;

	for(logs=0;;logs++)
	{
		size_t rlen; //表示已经收到的字节
		//len 表示总的数据包字节大小

		//每次接收完一个完整的MLogRec
		for(size_t len=sizeof(log);len;len-=rlen)
		{
			if((rlen = recv(m_connfd,(char*)&log+(sizeof(log)-len),len,0)) <= 0 ) //0表示客户端断线
			{
				goto escape;
			}
		}

		//由网络字节序转换为本机字节序(大端-->小端)
		log.pid = ntohl(log.pid);
		log.logintime  = ntohl(log.logintime);
		log.logouttime = ntohl(log.logouttime);
		log.durations  = ntohl(log.durations);

		//g_LogBuffer.operator<<(log)
		//将日志压入缓冲池(匹配记录链表)
		g_LogBuffer << log;
	}

escape:
	cout << "接收到" << logs << "条日志记录" << endl;
	//关闭socket
	close(m_connfd);
	//释放当前客户端线程
	delete this;
}
