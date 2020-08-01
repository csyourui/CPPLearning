#include "Mystrcmp.h"
#include <iostream>
using namespace std;

int main(){
    char str1[] = "abcd";
    char str2[] = "abc";
    cout<<strcmp(str1, str2)<<endl;
    
    char src1[] = "world";
    char dest1[] = "hello ";
    cout<<strcat(dest1, src1)<<endl;
    
    char src2[] = "world";
    char dest2[100];
    cout<<strcpy(dest2, src2)<<endl;
}
