//
//  66_构建乘积数组.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

vector<int> multiply(const vector<int>& A) {
    int N = (int)A.size();
    vector<int> B(N);
    int i = 0, j = N-1, product;
    product = 1;
    while(i < N){
        B[i] = product;
        product *= A[i];
        i++;
    }
    product = 1;
    while(j >=0){
        B[j] *= product;
        product *= A[j];
        j--;
    }
    return B;
}
