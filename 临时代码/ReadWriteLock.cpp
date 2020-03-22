//
//  ReadWriteLock.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/5.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class readwrite_lock
{
public:
    readwrite_lock(){
        read_cnt = 0;
    }
    void readLock(){
        read_mtx.lock();
        if(++read_cnt == 1)
            write_mtr.lock();
        read_mtx.unlock();
    }
    void readUnlock(){
        read_mtx.lock();
        if(--read_cnt == 0)
            write_mtr.unlock();
        read_mtx.unlock();
    }
    void writeLock(){
        write_mtr.lock();
    }
    void writeUnlock(){
        write_mtr.unlock();
    }
private:
    mutex read_mtx;
    mutex write_mtr;
    int read_cnt;
};
