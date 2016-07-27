#include "logBuffer.h"
/*
   private:
   pthread_mutex_t m_mutex//互斥量
   pthread_cond_t m_cond //条件变量
   list<MLogRec> m_logs//缓冲链表
 */

//构造函数
LogBuffer::LogBuffer(void)
{
	//初始化成员变量
	pthread_mutex_init(&m_mutex,0);
	pthread_cond_init(&m_cond,0);
}
//压入匹配记录到链表中
LogBuffer& LogBuffer::operator <<(const MLogRec& log){
	cout<<"压入匹配记录开始"<<endl;
	//加锁
	pthread_mutex_lock(&m_mutex);
	//将数据压入缓冲池  //这用的是链表，所以内存够用没有上限不用判断
	//所以就不会唤醒：阻塞生产者线程生产
	//如果链表表满，
	//阻塞生产者线程
	//pthread_cond_wait(&m_cond,&m_mutex);
	m_logs.push_back(log);
	//唤醒消费者线程进行消费
	pthread_cond_signal(&m_cond);
	//释放锁
	pthread_mutex_unlock(&m_mutex);
	cout<<"压入匹配记录结束"<<endl;
	return *this;//返回对象用*
}
//从链表中弹出匹配记录
LogBuffer& LogBuffer::operator >>(MLogRec& log){
	cout<<"弹出匹配记录开始"<<endl;
	//加锁
	pthread_mutex_lock(&m_mutex);
	if(m_logs.empty()) 
	{
		cout <<"等待日志记录"<<endl;
		//阻塞消费者线程消费
		pthread_cond_wait(&m_cond,&m_mutex);
	}
	//取出第一条记录
	log = m_logs.front(); //参数是引用类型作为返回值返回了
	//从链表中删除这条记录
	m_logs.pop_front();	
	//释放锁
	pthread_mutex_unlock(&m_mutex);
	cout<<"弹出匹配记录结束"<<endl;
	return *this;
}
//定义一个对象给后面的程序使用
LogBuffer g_LogBuffer;
