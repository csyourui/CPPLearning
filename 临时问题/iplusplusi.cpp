
//
//  iplusplusi.cpp
//  test
//
//  Created by yourui on 2020/2/28.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
//++i
int & int::operator++()
{
    *this += 1;
    return *this;
}

//i++
const int int::operator(int)
{
    int oldValue = *this;
    ++(*this);
    return oldvalue;
}
