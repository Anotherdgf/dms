
#ifndef __SOCKETSENDER_H__
#define __SOCKETSENDER_H__

#include "logSender.h"

/*日志发送器logSender接口的子类:抽象类*/
//套接字发送

class SocketSender:public LogSender
{
	private:
		string m_ip;//ip地址
		short m_port;//端口
		string m_failFile;//失败日志文件
		int m_sockfd;//客户端socket 套接字

	public:
		//构造函数重载
		SocketSender(const string& ip,short port,const string& failFile);

		//虚函数的覆盖版本
	    void sendLog(list<MLogRec>& logs)throw (SendException);
		

	private:
		//连接服务器
		void connectServer(void) throw(SocketException);
        //读取失败文件
		void readFailFile(list<MLogRec>& log) throw(ReadException);
		//发送日志
		void sendData(list<MLogRec>& log) throw(SendException);
		//保存失败的日志文件
		void saveFailFile(list<MLogRec>& log) throw(SaveException);

};
#endif
