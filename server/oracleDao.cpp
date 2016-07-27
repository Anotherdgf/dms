#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include "oracleDao.h"
using namespace std;

//构造函数
OracleDao::OracleDao(const string& username,const string& password)
{
	cout <<"连接数据库开始"<<endl;

	cout <<"连接数据库结束"<<endl;
}
//析构函数
OracleDao::~OracleDao(void)
{
	cout <<"关闭数据库开始"<<endl;

	cout <<"关闭数据库结束"<<endl;
}
//插入日志数据
void OracleDao::insert(const MLogRec& log) throw (DBException)
{	
	cout<<"插入数据开始"<<endl;

	cout<<"插入数据结束"<<endl;
}
