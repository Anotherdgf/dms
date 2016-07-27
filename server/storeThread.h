#ifndef __STORETHREAD_H__
#define __STORETHREAD_H__
#include "logThread.h"
#include "logDao.h"

using namespace std;

class StoreThread:public LogThread
{
	private:
		LogDao& m_dao;//数据类的对象

	public:
		StoreThread(LogDao& dao);

		//虚函数的覆盖版本
		void run(void);
};
#endif
