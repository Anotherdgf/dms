#include "client.h"

//构造函数
Client::Client(LogReader& reader,LogSender& sender):m_reader(reader),m_sender(sender){}

// 采集数据
void Client::dataMine(void)
{
	cout << "采集数据开始！" << endl;

	m_sender.sendLog(m_reader.readLog());

	cout << "采集数据结束！" << endl;
}

