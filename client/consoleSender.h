#ifndef __CONSOLESENDER_H__
#define __CONSOLESENDER_H__

#include "logSender.h"

/*日志发送器logSender 接口的子类：抽象类*/
class ConsoleSender:public LogSender
{
	public:
		//纯虚函数覆盖
		virtual void sendLog(list<MLogRec>& logs) throw(SendException);

};
#endif
