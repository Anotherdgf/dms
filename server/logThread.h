/*
 服务器线程处理接口：抽象类
 */
#ifndef LOGTHREAD_H__
#define LOGTHREAD_H__
#include "except.h"

class LogThread
{
	public:
		//虚析构函数 
		virtual ~LogThread(void){};

		//启动线程的函数
		void start(void) throw (ThreadException);

		//纯虚函数
		virtual void run(void) = 0;

	private:
		static void* run(void* arg);

};
#endif
