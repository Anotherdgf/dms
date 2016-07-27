/*服务器端各种异常的声明*/

#ifndef __EXCEPT_H__
#define __EXCEPT_H__
#include <exception>
#include <string>

using namespace std;

//基类
class ServerException:public exception
{
	private:
		string m_msg;//存放异常信息
	public:
		ServerException (void):m_msg("服务器异常！"){};
		ServerException(const string& msg):m_msg("服务器异常！")
	{
		m_msg += msg;
		m_msg +="!";
	}
		//析构函数
		~ServerException (void) throw(){}

		//what
		const char * what(void) const throw()
		{
			return m_msg.c_str();
		}
};

//数据库连接异常类
class DBException:public ServerException
{
	public:
		DBException(void):ServerException("数据库错误！"){}
		DBException(const string& msg):ServerException(msg){}
};

//Socket异常类
class SocketException:public ServerException
{
	public:
		SocketException(void):ServerException("Socket 错误！"){}
		SocketException(const string& msg):ServerException(msg){}
};


//线程异常类
class ThreadException:public ServerException
{
	public:
		ThreadException(void):ServerException("线程执行错误！"){}
		ThreadException(const string& msg):ServerException(msg){}
};
#endif
