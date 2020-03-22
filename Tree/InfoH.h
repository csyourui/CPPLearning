//
//  InfoH.hpp
//  Tree
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//

#ifndef INFOH_H
#define INFOH_H
 
#define INFI  ((unsigned int)-1)
 
struct InfoH {
    int pos;
    bool newline;
 
    InfoH() : pos(INFI), newline(false) {}
 
    int add_pos(int add) {
        pos += add;
        return pos;
    }
};
 
 
#endif


