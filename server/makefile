CC = g++ #指定g++作为编译器
RM = rm -rf #指定删除的指令
CFLAGS = -c -Wall #指定编译的选项
server:main.o fileDao.o oracleDao.o logBuffer.o logThread.o storeThread.o clientThread.o serverSocket.o server.o
#	$(CC) $^ -lpthread -o $@ #由依赖文件生成目标文件
	$(CC) $^ -lpthread -lnsl -o $@
main.o:main.cpp
	$(CC) $(CFLAGS) $^ #g++ -c -Wall main.cpp
fileDao.o:fileDao.cpp
	$(CC) $(CFLAGS) $^
oracleDao.o:oracleDao.cpp
	$(CC) $(CFLAGS) $^
logBuffer.o:logBuffer.cpp
	$(CC) $(CFLAGS) $^
logThread.o:logThread.cpp
	$(CC) $(CFLAGS) $^
storeThread.o:storeThread.cpp
	$(CC) $(CFLAGS) $^
clientThread.o:clientThread.cpp
	$(CC) $(CFLAGS) $^
serverSocket.o:serverSocket.cpp
	$(CC) $(CFLAGS) $^
server.o:server.cpp
	$(CC) $(CFLAGS) $^
clean:
	$(RM) server *.o *.gch *.*~
