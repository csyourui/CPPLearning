//
//  PrimeD.cpp
//  test
//
//  Created by yourui on 2020/2/27.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define N 600851475143

int main(){
    long long int i = 2, n = N;
    printf("%lld = ", n);
    while(i <= n){
        if(n % i == 0){
            printf("%lld", i);
            n = n / i;
            if(n != 1)
                printf(" * ");
        }
        else
            i++;
    }
    printf("\n");
    return 0;
}

