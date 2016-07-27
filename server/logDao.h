#ifndef __LOGDAO_H__
#define __LOGDAO_H__

#include "except.h"
#include "data.h"

/*
 服务器端日志处理接口：抽象类
 */

class LogDao
{
	public:
		//纯虚函数
		virtual void insert(const MLogRec& log) throw (DBException) = 0;
		//虚析构
		virtual ~LogDao(void){}
};
#endif
