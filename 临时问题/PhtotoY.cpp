////
////  PhtotoY.cpp
////  test
////
////  Created by yourui on 2020/2/25.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//// 参考程序
//#include <cstring>
//#include <iostream>
//#include <vector>
//#include <cstdio>
//using namespace std;
//char str[1010];
//int N;
//int main(){
//    scanf("%d\n", &N);
//    // TODO: 读入字符串，注意可能含空格
//    for(int i = 0; i < N; i++){
//        char c = getchar();
//        if(c != '\n' && c!= '\0')
//            str[i] = c;
//    }
//    // TODO: 输出拍照队形，没人用空格占位
//    int K = (N - 1) / 3;
//    int order = 0;
//    for (int i = 0 ; i < K; i++) {
//        string a = "";
//        for (int j = 0; j < i; j++) {
//            a += ' ';
//        }
//        a += str[order++];
//        for (int j = 0; j < 2*K-2*i-1; j++) {
//            a += ' ';
//        }
//        a += str[order++];
//        cout<<a<<endl;
//    }
//    for (int i = K ; i < 2*K+1; i++) {
//        string a = "";
//        for (int j = 0; j < K; j++) {
//            a += ' ';
//        }
//        a += str[order++];
//        cout<<a<<endl;
//    }
//}
//
//
