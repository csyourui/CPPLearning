//
//  京东笔试题.cpp
//  C++Learning
//
//  Created by yourui on 2020/4/18.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 
 n是现有股票数，m是每天最多能卖出的股票数;
 a[n]是股票0~n每天亏损的钱，也就是说如果保留i股在手上k天后再卖就亏损k*a[i]元;
 q[Q]是他的输入，比如q[0]=3意味着至少要卖3股;
 你需要输出一个数列L[Q]，比如L[0]意味着至少要卖q[0]股时，最少亏损多少钱
 */
#include <stdio.h>
