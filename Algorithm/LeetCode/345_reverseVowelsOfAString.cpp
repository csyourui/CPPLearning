// Source : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author : csyourui
// Date   : 2020-03-19

/***************************************************************************************************** 
 *
 * Write a function that takes a string as input and reverse only the vowels of a string.
 * 
 * Example 1:
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * Example 2:
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 ******************************************************************************************************/

class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||\
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string reverseVowels(string s) {
        int left = 0, right = s.length()-1;
        while(left < right){
            while(left < right && !isVowel(s[left])) left++;
            while(left < right && !isVowel(s[right])) right--;
            if(left >= right) break;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};