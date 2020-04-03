//
//  i++.cpp
//  test
//
//  Created by yourui on 2020/3/14.
//  Copyright © 2020 yourui. All rights reserved.
//
class Test{
    
};
// ++i
int & int::operator++(){
    (*this) += 1;
    return *this;
}

// i++
int int::operator++(int){
    int oldVal = *this;
    ++(*this);
    return oldVal;
}

ostream& operator<<(ostream &out, Test &test){
    
}
