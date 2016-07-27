#ifndef __FILEDAO_H__
#define __FILEDAO_H__
#include "logDao.h"
#include <fstream>

using namespace std;

class FileDao:public LogDao
{
	private:
		ofstream m_ofs;

	public:
		FileDao(const string& path);
		void insert(const MLogRec& log) throw (DBException);
		~FileDao(void);

};

#endif
