
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "logSender.h"
#include "logReader.h"
#include "except.h"


/*客户端类*/
class Client{
	//成员变量
	private:
		LogReader& m_reader;
		LogSender& m_sender;

	public:
		//构造函数
		Client(LogReader& reader,LogSender& sender);

		//采集数据
		void dataMine(void);
};
#endif
