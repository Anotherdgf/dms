/*
 日志发送器接口声明
 */
#ifndef __LOGSENDER_H__
#define __LOGSENDER_H__
#include <list>
#include "except.h"
#include "data.h"

/*
   日志发送器接口(抽象类)
 */

class LogSender
{
	public:
		//纯虚函数
		virtual void sendLog(list<MLogRec>& logs) throw (SendException) = 0;

		//虚析构函数
		virtual ~LogSender(void){}
};
#endif
