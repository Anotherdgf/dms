#include "fileDao.h"
/*
   private:
   ofstream m_ofs{}
 */
//构造函数
FileDao::FileDao(const string& path)
{
	cout << "打开数据库文件开始"<<endl;
	m_ofs.open(path.c_str(),ios::app);// 以追加方式打开文件 
	if(!m_ofs)
	{
		throw DBException("打开数据库文件失败");
	}
	cout << "打开数据库文件结束"<<endl;
}
//析构函数
FileDao::~FileDao(void)
{
	cout <<"关闭数据库文件开始"<<endl;
	m_ofs.close();
	cout <<"关闭数据库文件结束"<<endl;
}
void FileDao::insert(const MLogRec& log)throw (DBException)
{
	cout << "写入日志开始"<<endl;
	m_ofs << log << endl;
	cout <<"写入日志结束"<<endl;
}
