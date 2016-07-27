#ifndef __LOGBUFFER_H__
#define __LOGBUFFER_H__

#include "data.h"
#include <list>
#include <pthread.h>
class LogBuffer
{
	private:
		pthread_mutex_t m_mutex;//互斥量
		pthread_cond_t m_cond;//条件变更
		list <MLogRec> m_logs;//缓冲区链表(客户端上传到服务器的日志数据)

	public:
		LogBuffer(void);

		//压入匹配日志记录到链表中
		LogBuffer& operator << (const MLogRec& log);

		//从链表中取得匹配的日志记录 
		LogBuffer& operator  >> (MLogRec& log);

};

//主要用途就是为方便其它调用模块使用
extern LogBuffer g_LogBuffer;
#endif
