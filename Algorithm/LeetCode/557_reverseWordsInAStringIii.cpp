// Source : https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author : csyourui
// Date   : 2020-03-19

/***************************************************************************************************** 
 *
 * Given a string, you need to reverse the order of characters in each word within a sentence while 
 * still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be any extra space in the 
 * string.
 ******************************************************************************************************/

class Solution {
public:
    void reverseHelper(string &s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int pos1 = 0;
        int pos2 = s.find(' ');
        while(pos2!=s.npos){
            reverseHelper(s, pos1, pos2-1);
            pos1 = pos2+1;
            pos2 = s.find(' ', pos1);
        }
        if(pos1 != s.length())
            reverseHelper(s, pos1, s.length()-1);
        return s;
    }
};