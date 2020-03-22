//
//  VectorOddEven.cpp
//  test
//
//  Created by yourui on 2020/3/1.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    //int &a = a;
    int temp = a;
    a = b;
    b = temp;
}
void reOrderArray(vector<int> &array) {
    //1,2,3,4,5
    //1,3,5,2,4
    int N = array.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-i-1;j++){
            if(array[j]%2==0 && array[j+1]%2!=0){
                swap(array[j], array[j+1]);
            }
        }
    }
}
int main(){
//    int N;
//    while (cin >> N) {
//        vector<int> array(N);
//
//        for (int i = 0; i < N; i++) {
//            cin >> array[i];
//        }
//        reOrderArray(array);
//
//        for (int i = 0; i < N; i++) {
//            cout << array[i] <<" ";
//        }
//        cout<<endl;
//    }
    int a = 2, b =5;
    int &c = a;
    c--;
    //swap(a, b);
    //cout<<a<<" "<<b<<endl;
    cout<<c<<endl;
}
