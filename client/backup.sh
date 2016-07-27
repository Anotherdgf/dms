#!/bin/bash

#拷贝$1 第一个参数指定的内容到第二个参数$2的内容中,错误丢弃
# backup.sh wtmpx wtmpx.2015...
if cp $1 $2 >& /dev/null 
	then
 		if cat /dev/null > $1   #清空$1
 		then
   		 	exit 0 #清空成功退出码0
		else 
		 	exit 1 #清空失败
		fi
    else #如果拷贝失败退出码2
		exit 2
	fi
