//
//  main.cpp
//  Tree
//
//  Created by yourui on 2020/3/2.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
#include "bst.h"
#include "VisualTree.h"
 
 
int main(int argc, char*argv[])
{
    typedef int                 ValueType;
    typedef TreeNode<ValueType> NodeType;
 
    BSTree<ValueType>                tree;
    VisualTree<NodeType, ValueType>  vtree(&NodeType::parent,
                                            &NodeType::left,
                                            &NodeType::right,
                                            &NodeType::val);

    int num = 15;
    srand(time(NULL));
    for (int i = 0; i < num; ++i) {
        ValueType v = rand() % 1000;  // 随机生成一个[0，1000)的数
        tree.insert(v);
        std::cout << "insert : " << v << std::endl;
        vtree.draw(tree.root());
    }
    return 0;
}

