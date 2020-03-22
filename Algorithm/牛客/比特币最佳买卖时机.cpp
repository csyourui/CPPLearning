//
//  比特币最佳买卖时机.cpp
//  Main
//
//  Created by yourui on 2020/3/19.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
*********************************************************************************
*题目描述：
*给定一个正整数数组，它的第 i 个元素是比特币第 i 天的价格。
*如果你最多只允许完成一笔交易（即买入和卖出一次），设计一个算法来计算你所能获取的最大利润。
*注意你不能在买入比特币前卖出
*
*输入描述：
*正整数数组，为以空格分隔的n个正整数
*
*输出描述：
*最大利润
*
*示例1：
*输入：7 1 5 3 6 4
*输出：5

*********************************************************************************
*/

#include <iostream>
#include <vector>
#include "limits.h"

using namespace std;
int main(){
    int a,ma = 0,mi = INT_MAX;
    while( cin >> a){
        ma = max(a - mi,ma);
        mi = min(a, mi);
    }
    cout<<ma<<endl;
}
