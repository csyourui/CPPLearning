//
//  Fork.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/6.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(){
    pid_t pid;
    signal(SIGCHLD, SIG_IGN);//处理僵尸进程
    printf("befor fork pid: %d\n", getpid());
    int abc = 10;
    pid = fork();
    if(pid == -1){
        perror("tile");
        return -1;
    }
    if(pid > 0){
        abc++;
        printf("parent:pid:%d \n",getpid());
        printf("abc:%d \n", abc);
        sleep(20);
    }
    else if (pid == 0){
        abc++;
        printf("child:%d, parent:%d\n", getpid(), getppid());
        printf("abc:%d \n", abc);
    }
    printf("fork after..\n");
}
