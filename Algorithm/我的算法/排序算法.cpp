//
//  SortAlgorithms.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/9.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void my_swap(T &a, T &b){
    T temp(a);
    a = b;
    b = temp;
}

//冒泡排序
template<typename T>
void bubbleSort(vector<T> &v){
    int N = v.size();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - i - 1; j++){
            if(v[j] > v[j+1]){
                my_swap(v[j], v[j+1]);
            }
        }
    }
}

//插入排序
template<typename T>
void insertSort(vector<T> &v){
    int N = v.size();
    for (int i = 1; i < N; i++){
        for(int j = i; j >= 1 && v[j] < v[j-1]; j--){
            swap(v[j], v[j-1]);
        }
    }
}

//选择排序
template<typename T>
void selectSort(vector<T> &v){
    int N = v.size();
    for (int i = 0; i < N; i++){
        int min = i;
        for (int j = i + 1; j < N; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        my_swap(v[i], v[min]);
    }
}


//堆排序
//     i
//    / \
//   c1 c2
template<typename T>
void maxHeapify(vector<T>& v, int i, int n){
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    while(c1 <= n){
        int max = i;
        if(v[c1] > v[max]) max = c1;
        if(c2 <= n && v[c2] > v[max]) max = c2;
        if(max == i)
            return;
        else{
            my_swap(v[i], v[max]);
            i = max;
            c1 = i * 2 + 1;
            c2 = i * 2 + 2;
        }
    }
}
template<typename T>
void heapSort(vector<T> &v){
    int N = v.size();
    //从N/2-1处开始heapify
    for(int i = N/2 - 1; i >= 0; i--){
        maxHeapify(v, i, N - 1);
    }
    //将堆顶元素交换到数组末尾，减少数组长度，进行heapify
    for (int i = N - 1; i > 0; i--){
        swap(v[0], v[i]);
        maxHeapify(v, 0, i - 1);
    }
}

//希尔排序
template<typename T>
void shellSort(vector<T>&v){
    int N = v.size();
    int h = 1;
    while (h < N / 3) {
        h = 3 * h + 1; // 1, 4, 13, 40, ...
    }
    while (h >= 1) {
        for (int i = h; i < N; i++) {
            for (int j = i; j >= h && v[j] < v[j - h]; j -= h) {
                swap(v[j], v[j - h]);
            }
        }
        h /= 3;
    }
}

//桶排序
void bucketSort(vector<int> &v){
    int N = (int)v.size();
    int maxV = 20;
    vector<int> bucket(maxV);
    for (int i = 0; i < N; i++){
        bucket[v[i]]++;
    }
    int count = 0;
    for (int i = 0; i < maxV; i++){
        while(bucket[i]--){
            v[count++] = i;
        }
    }
}
//快速排序
template<typename T>
int partition(vector<T>& v,int start,int end){
    int pivot = v[start];
    while(start < end) {
        while(start < end && v[end] >= pivot) end--;
        v[start] = v[end];
        while(start < end && v[start] <= pivot) start++;
        v[end] = v[start];
    }
    v[start] = pivot;
    return start;
}
template<typename T>
void quickSort(vector<T>& v,int start,int end){
    if(start < end) {
        int pivotpos = partition(v,start,end);
        quickSort(v, start, pivotpos-1);
        quickSort(v, pivotpos+1, end);
    }
}

//归并排序
template<typename T>
void merge(vector<T>&v, int start, int mid, int end){
    vector<T> result(end-start+1);
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end){
        if(v[i] <= v[j])
            result[k++] = v[i++];
        else
            result[k++] = v[j++];
    }
    while(i <= mid)
        result[k++] = v[i++];
    while(j <= end)
        result[k++] = v[j++];
    for(int i = start ; i <= end; i++){
        v[i] = result[i-start];
    }
}
template<typename T>
void mergeSort(vector<T> &v, int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}


template<typename T>
void printVector(vector<T> v){
    for (int i = 0; i < (int)v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

//仿函数，重载()运算符
template<class T>
struct myless{
    bool operator()(const T&a, const T&b){
        return a < b;
    }
};

template<typename T>
static bool mycmp(const T& a, const T& b){
    return a < b;
}

int main(){
    vector<int> v0 = {6,2,5,3,11,1,10,0,9,8,7,4};
    vector<int> a = {0,1,2,3,4,5,6,7,8};
    vector<int> result = v0;
    printVector(v0);
    //bubbleSort(v0);
    //insertSort(v0);
    //selectSort(v0);
    //heapSort(v0);
    //shellSort(v0);
    //bucketSort(v0);
    //quickSort(v0,0,v0.size()-1);
    
    //mergeSort(v0, 0, (int)v0.size()-1,result);
    //v0 = result;
    
    //cmp函数
    //sort(v0.begin(), v0.end(), mycmp<int>);
    //lambad表达式
    //sort(v0.begin(), v0.end(), [](int x, int y)->bool{return x < y;});
    //仿函数
    sort(v0.begin(), v0.end(), myless<int>());

    printVector(v0);


    return 0;
}
