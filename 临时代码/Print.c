//
//  Print.c
//  TEXT
//
//  Created by yourui on 2020/3/8.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#define R 5
#define C 10
#define WIDTH 8
char letter[26][R][C] = {
    {"    #    ",
     "   # #   ",
     "  #####  ",
     " #     # ",
     "#       #"},
    
    {" ######  ",
     " #     # ",
     " ######  ",
     " #     # ",
     " ######  "},
    
    {"  ####   ",
     " #    #  ",
     " #       ",
     " #    #  ",
     "  ####   "},
    
    {" #####   ",
     " #    #  ",
     " #    #  ",
     " #    #  ",
     " #####   "},
    
    {" ######  ",
     " #       ",
     " ######  ",
     " #       ",
     " ######  "},
    
    {" ######  ",
     " #       ",
     " ######  ",
     " #       ",
     " #       "},
    
    {"  ####   ",
     " #       ",
     " #  ###  ",
     " #    #  ",
     "  ####   "},
     
    {" #    #  ",
     " #    #  ",
     " ######  ",
     " #    #  ",
     " #    #  "},
    
    {"  #####  ",
     "    #    ",
     "    #    ",
     "    #    ",
     "  #####  "},
     
    {"  ###### ",
     "      #  ",
     "      #  ",
     " #    #  ",
     "  ####   "},
    
    {" #    #  ",
     " #  #    ",
     " ####    ",
     " #   #   ",
     " #    #  "},
    
    {" #       ",
     " #       ",
     " #       ",
     " #       ",
     " ######  "},
    
    {" ##   ## ",
     "#  # #  #",
     "#   #   #",
     "#   #   #",
     "#   #   #"},
    
    {" #     # ",
     " # #   # ",
     " #  #  # ",
     " #   # # ",
     " #     # "},
    
    {"  #####  ",
     " #     # ",
     " #     # ",
     " #     # ",
     "  #####  "},
    
    {" ######  ",
     " #     # ",
     " ######  ",
     " #       ",
     " #       "},
    
    {"  #####  ",
     " #     # ",
     " #   # # ",
     " #    ## ",
     "  #######"},
    
    {" ######  ",
     " #     # ",
     " #####   ",
     " #    #  ",
     " #     # "},
    
    {"  #####  ",
     " #       ",
     "  #####  ",
     "      #  ",
     " #####   "},
    
    {" ####### ",
     "    #    ",
     "    #    ",
     "    #    ",
     "    #    "},
    
    {" #     # ",
     " #     # ",
     " #     # ",
     " #     # ",
     "  #####  "},
    
    {"#       #",
     " #     # ",
     "  #   #  ",
     "   # #   ",
     "    #    "},
    
    {"#   #   #",
     "#   #   #",
     "#   #   #",
     "#   #   #",
     " ##   ## "},
    
    {" #     # ",
     "   # #   ",
     "    #    ",
     "   # #   ",
     " #     # "},
    
    {" #     # ",
     "  #   #  ",
     "   # #   ",
     "    #    ",
     "    #    "},
    
    {" ####### ",
     "      #  ",
     "    #    ",
     "  #      ",
     " ####### "}
};
void print(char *str){
    int start = 0;
    while(start < strlen(str)){
        for (int i = 0; i < R; i++) {
            for(int j = start; j < start + WIDTH && j < strlen(str); j++){
                if(str[j] == ' ')
                    printf("         ");
                else
                 printf("%s", letter[toupper(str[j])-'A'][i]);
            }
            printf("\n");
        }
        start += WIDTH;
        printf("\n");
    }
}

int main(){
    char *str = "abalafdsjclsosf";
    print(str);
    return 0;
}
