//
//  pos_adder.hpp
//  Tree
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//

#ifndef POS_ADDER_H
#define POS_ADDER_H
 
#include "InfoH.h"
 
class PosAdder
{
public:
    PosAdder(int n_) : n(n_) {}
    int operator() (InfoH *node) { return node->add_pos(n); }
private:
    int n;
};
 
#endif // POS_ADDER_H


