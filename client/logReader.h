#ifndef __LOGREADER_H__
#define __LOGREADER_H__

#include <string>
#include "data.h"
#include "except.h"
#include <list>

using namespace std;

class LogReader
{

	// 成员变量
	private:
		string m_logFile;//日志文件名
		string m_loginsFile;//剩余的登入记录
		string m_backupFile;//备份文件名
		list<LogRec> m_logins;//所有登入记录 
		list<LogRec> m_logouts;//所有登出记录 
		list<MLogRec> m_logs;//所有匹配记录

	//私有成员函数
	private:
		//备份日志文件
		void backup(void)throw (BackupException);
		//读取上次未匹配的记录
		void readLoginsFile(void) throw(ReadException);
		//读取备份日志文件
		void readBackupFile(void) throw (ReadException);
		//匹配登入/登出记录
		void match(void);
		//保存未匹配的登入记录
		void saveLoginsFile(void) throw (SaveException);

	public:
		//构造函数
		LogReader(const string& logFile,const string& loginsFile);
		//读取日志
		list<MLogRec>&  readLog(void) throw(ReadException);

};
#endif
