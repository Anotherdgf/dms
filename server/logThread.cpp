#include "logThread.h"
#include "pthread.h"
#include <iostream>
using namespace std;

//启动线程
void LogThread::start(void)throw (ThreadException)
{
	cout << "启动线程开始"<<endl;
	//创建一个新的线程，将this指针传给线程处理函数，在线程处理函数真正调用run 
	pthread_t tid;
	if(pthread_create(&tid,0,run,this)) //pthread_create()函数参数中没有this，
		//所以调用时封装了一个static的run ，并将当前类作为实参传给了形参
	{
		throw ThreadException("启动线线程失败");
	}
	cout << "启动线程结束"<<endl;
}
void* LogThread::run(void* arg) //静态的run 
{
	//分离当前线程
	pthread_detach(pthread_self());
	//调真正的run函数，在实现类中进行了覆盖
	static_cast<LogThread*>(arg)->run();//将arg转换为当前类类型的指针

	return NULL;
}
