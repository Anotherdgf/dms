
/*
 自定义登录记录和匹配记录类型
 */
#ifndef __DATA_H__
#define __DATA_H__
#include <iostream>
#include <unistd.h>

using namespace std;

//登录记录
typedef struct LogRec
{
	char logname[32];
	char logip[257];
	short type;//登录类型 7 :登入 8 :登出
	pid_t pid; //登录进程ID
	long logtime;//登录时刻



	

}LogRec;


//匹配记录
typedef struct MLogRec
{
	char logname [32];
	char logip[257];
	pid_t pid;
	long logintime;//登录时刻
	long logouttime;//登出时刻
	long durations;//在线时长

	//定义输出运算符重载(cout << MLogRec << endl;)
	friend ostream& operator << (ostream& os,const MLogRec& log)
	{
      return os << log.logname <<"," << log.logip << "," <<
		  log.pid << "," << log.logintime << "," << log.logouttime << "," << log.durations;

    }

}MLogRec;
#endif

