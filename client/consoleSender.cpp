
#include "consoleSender.h"
void ConsoleSender::sendLog(list<MLogRec>& logs) throw(SendException)
{
	cout << "控制台发送日志开始..."<<endl;
	//遍历所有匹配的记录
	for(list<MLogRec>::iterator it = logs.begin();it != logs.end(); it++)
	{
		cout << *it << endl;	
	}
	cout << "控制台发送日志结束！"<<endl;
}
