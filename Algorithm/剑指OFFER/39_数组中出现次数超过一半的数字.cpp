//
//  39_数组中出现次数超过一半的数字.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/27.
//  Copyright © 2020 yourui. All rights reserved.
//

//摩尔投票算法(Boyer-Moore Majority Vote Algorithm)
int MoreThanHalfNum_Solution(vector<int> numbers) {
    int m = 0, count = 0;
    for(int i = 0; i < numbers.size(); i++){
        if(count == 0){
            m = numbers[i];
            count++;
        }else{
            if(numbers[i] == m)
                count++;
            else
                count--;
        }
    }
    count = 0;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == m) count++;
    }
    return count > numbers.size()/2 ? m:0;
}
