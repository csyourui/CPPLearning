#include <stdio.h>
 

void printHello(char *hello){
     printf("%s\n",hello);
}
void printWorld(char *World){
     printf("%s\n",World);
}
void callBack(void(*pFunc)(char *),char *words){
    pFunc(words);
}

int main(void){
    callBack(printHello,"Hello");
    callBack(printWorld,"World");
}
 

