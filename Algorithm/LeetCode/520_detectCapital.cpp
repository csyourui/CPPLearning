// Source : https://leetcode.com/problems/detect-capital/submissions/
// Author : csyourui
// Date   : 2020-03-19

/***************************************************************************************************** 
 *
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * 
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * 
 * 	All letters in this word are capitals, like "USA".
 * 	All letters in this word are not capitals, like "leetcode".
 * 	Only the first letter in this word is capital, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 ******************************************************************************************************/
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = true;
        //1
        for(int i = 0; i < word.length(); i++){
            if(islower(word[i])) flag = false;
        }
        if(flag) return flag;
        //2
        flag = true;
        for(int i = 0; i < word.length(); i++){
            if(isupper(word[i])) flag = false;
        }
        if(flag) return flag;
        //3
        flag = isupper(word[0]);
        for(int i = 1; i < word.length(); i++){
            if(isupper(word[i])) flag = false;
        }
        
        return flag;
    }
};
