
#include "storeThread.h"
#include "data.h"
#include "logBuffer.h"
/*
   private:
   LogDao& m_dao;//数据访问类
 */
//构造
StoreThread::StoreThread(LogDao& dao):m_dao(dao){}

//真正的run函数
void StoreThread::run(void)
{
	//不断从缓冲区中取出数据放到数据库中
	MLogRec log;
	for(;;)
	{
		//g_LogBuffer.operator>>(log);  运算符重载
		g_LogBuffer >> log; //从缓冲区中取数据
		try
		{
			m_dao.insert(log);
		}
		catch(DBException ex)
		{
			cout << ex.what() <<endl;
		}
	}
}
