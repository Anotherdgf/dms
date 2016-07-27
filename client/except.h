/*定义各种类型的异常*/

#ifndef __EXCEPT_H__
#define __EXCEPT_H__
#include <exception>
#include <string>

using namespace std;

class ClientException:public exception
{
	private:
		string m_msg;//存放异常信息

	public:
		//构造
		ClientException (void):m_msg("客户机异常！"){}
		//构造重载
		ClientException (const string& msg):m_msg("客户机异常")
		{
			m_msg += msg;
			m_msg +="!";
		}
		//析构函数
		~ClientException (void) throw(){}

		//what 
		const char* what(void) const throw()
		{
			// 返回C风格的字符串
			return m_msg.c_str();
		}
};

//Backup异常类
class BackupException:public ClientException
{
	public:
		BackupException (void):ClientException("备份错误！"){}
		//有参构造函数
		BackupException (const string& msg):ClientException(msg){} 
};

//Socket异常类
class SocketException:public ClientException
{
	public:
		SocketException (void):ClientException("Socket错误！"){}
		SocketException (const string& msg):ClientException(msg){} 
};

//Read异常类
class ReadException:public ClientException
{
	public:
		ReadException (void):ClientException("读取错误！"){}
		ReadException (const string& msg):ClientException(msg){} 
};

//Save异常类
class SaveException:public ClientException
{
	public:
		SaveException (void):ClientException("保存错误！"){}
		SaveException (const string& msg):ClientException(msg){} 
};

//Send异常类 
class SendException:public ClientException
{
	public:
		SendException (void):ClientException("发送错误！"){}
		SendException (const string& msg):ClientException(msg){} 
};
#endif

