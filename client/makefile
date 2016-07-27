CC = g++ #指定g++作为编译器
RM = rm -rf #指定删除指令
CFLAGS = -c -Wall #指定编译选项
client:main.o logReader.o consoleSender.o socketSender.o client.o
	$(CC) $^ -o $@  #根据依赖文件生成目标文件 g++ main.o logReader.o ... *.o  -o client 
main.o:main.cpp
	$(CC) $(CFLAGS) $^  #g++ main.o -c -wall client
clean:
	$(RM) client *.o *.gch *.*.swp
logReader.o:logReader.cpp
	$(CC) $(CFLAGS) $^ 
consoleSender.o:consoleSender.cpp
	$(CC) $(CFLAGS) $^ 
socketSender.o:socketSender.cpp
	$(CC) $(CFLAGS) $^ 
client.o:client.cpp
	$(CC) $(CFLAGS) $^ 
