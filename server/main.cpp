//服务器端的主函数
#include <iostream>
#include "fileDao.h"
#include "oracleDao.h"
#include "server.h"
using namespace std;

int main(void)
{
	try
	{	
		FileDao dao("./dms.db");
		//OracleDao dao("system","open123");
		Server server(dao,"",8888);
		server.dataMine();
	}
	catch(ServerException& ex)
	{
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}
