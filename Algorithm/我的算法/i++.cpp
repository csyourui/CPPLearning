//
//  i++.cpp
//  test
//
//  Created by yourui on 2020/3/14.
//  Copyright © 2020 yourui. All rights reserved.
//
// ++i
int& int::operator++(){
    (*this) += 1;
    return *this;
}

// i++
const int int::operator++(){
    int oldVal = *this;
    ++ (*this);
    return oldVal;
}
