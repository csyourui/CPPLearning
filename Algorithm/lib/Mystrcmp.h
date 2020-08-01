//
//  mystrcmp.h
//  C++Learning
//
//  Created by yourui on 2020/8/1.
//  Copyright © 2020 yourui. All rights reserved.
//

#ifndef mystrcmp_h
#define mystrcmp_h
#include <iostream>
int strcmp(const char* str1, const char* str2){
    assert((str1 != NULL) && (str1 != NULL));

    while(*str1 && *str1 == *str2){
        str1++;
        str2++;
    }
    if(*(unsigned char*)str1 < *(unsigned char*)str2)
        return -1;
    else if (*(unsigned char*)str1 > *(unsigned char*)str2)
        return 1;
    else return 0;
}
char *strcat(char *dest, const char *src){
    assert((dest != NULL) && (src != NULL));

    char *str = dest;
    while(*str != '\0'){
        str++;
    }
    while((*str++ = *src++) != '\0');
    return dest;
}
char *strcpy(char* dest, const char*src){
    assert((dest != NULL) && (src != NULL));
    char *str = dest;
    while((*str++ = *src++) != '\0'){};
    return dest;
}

void *memcopy( void* dest , const void* src , size_t n )
{
    assert(dest != NULL && src != NULL);
    
    char* newDest = (char*)dest;
    const char* newSrc = (const char*) src;
    while( n-- )
    {
        *newDest++ = *newSrc++;//内存地址递增
    }
    return dest;
}

void* memmove(void* dest, const void* src, size_t n)
{
    assert(dest != NULL && src != NULL);
    
    char* newDest = (char*)dest;
    const char* newSrc = (char*)src;
    if(newDest > newSrc && (newSrc + n > newDest)) {
        newDest = newDest + n - 1;
        newSrc = newSrc + n - 1;
        while(n--) {
            *newDest-- = *newSrc--;
        }
    }
    //无重叠
    else {
        while(n--) {
            *newDest++ = *newSrc++;
        }
    }
    return dest;
}

#endif /* mystrcmp_h */
