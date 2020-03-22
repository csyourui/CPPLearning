//#include <stdio.h>
//#include <math.h>
//#include <time.h>
//#define NUM 10
//
//int main()
//{
//    clock_t start, finish;
//    start = clock();
//
//    
//    int count = 2;
//    int i, j;
//    _Bool flag = 1;
//    
//    for(i = 5; i < NUM; i++)
//    {
//        for(int j = 2; j <= sqrt(i); j++)
//        {
//            if(i % j == 0)
//            {
//                flag = 0;
//                break;
//            }
//        }
//        
//        if(flag)
//        {
//            count++;
//        }
//        else
//        {
//            flag = 1;
//        }
//    }
//    
//    printf("%d以内共有%d个素数\n", NUM, count);
//    
//    finish = clock();
//    printf( "%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC );
//    return 0;
//}
