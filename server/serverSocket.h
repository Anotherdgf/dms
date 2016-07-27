/*server socket类*/
#ifndef __SERVERSOCKET_H__
#define	__SERVERSOCKET_H__
#include "except.h"
using namespace std;
class ServerSocket
{
	private:
		int m_sockfd;//socket描述符	
	public:
		ServerSocket(const string& ip,short port)throw (SocketException);
		//响应客户端的请求
		void acceptClient(void) throw(SocketException);
};
#endif
