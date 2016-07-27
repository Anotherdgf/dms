#ifndef ORACLEDAO_H
#define ORACLEDAO_H
#include "logDao.h"

class OracleDao : public LogDao
{
	public:
		//构造函数
		OracleDao(const string& username,const string& password);
		//析构函数
		~OracleDao(void);
		//插入函数
		void insert(const MLogRec& log) throw (DBException);
};
#endif

