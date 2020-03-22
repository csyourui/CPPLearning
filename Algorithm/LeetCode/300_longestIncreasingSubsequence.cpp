// Source : https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// Author : csyourui
// Date   : 2020-03-19

/***************************************************************************************************** 
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * 
 * Example:
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
 * 
 * Note: 
 * 
 * 	There may be more than one LIS combination, it is only necessary for you to return the 
 * length.
 * 	Your algorithm should run in O(n2) complexity.
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 ******************************************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        int res = 1;
        vector<int> dp(N);
        for(int i = 0; i < N; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    
/* 
 * Solution 1 - O(N^2)
 * =========
 *
 * LIS - longest increasing subsequence
 *
 * We iterate through the elements to find the LIS that ends with the current element. 
 * To do that we need to look at all of the previous elements and find one smaller than
 * the current one so that we can add the current one to the sequence terminated in the 
 * smaller one. The length of the LIS ending in the current element is the length of the
 * LIS ending in the smaller one + 1. To find the maximum current LIS we need to use the
 * maximum previous LIS that satisfies the conditions.
 * 
 */
    vector <int> longest_LIS;
    int lengthOfLIS(vector<int>& nums) {
        int answer = 0;
        if(nums.size())
        {   
            longest_LIS.push_back(1);
            answer = 1;
            for(int i = 1; i < nums.size(); i++)
            {
                int maximum = 1;
                for(int j = 0; j < longest_LIS.size(); j++)
                    if(nums[i] > nums[j])
                        maximum = max(maximum, longest_LIS[j] + 1);
                longest_LIS.push_back(maximum);
                answer = max(maximum, answer);
            }
        }
        return answer;
    }
/* 
 * Solution 2 - O(N * logN)
 * =========
 *
 * LIS - longest increasing subsequence
 * 
 * We iterate through the elements to find the position of the current element in the
 * current LIS. After we find its position we change the LIS replacing the next biggest 
 * element with the current one or increase the size of the sequence if the current element
 * is bigger than the biggest one. This way we keep the LIS with the smallest possible
 * elements. By keeping any other LIS we can encounter an element that could have been added
 * to the LIS with the smallest elements, but can't be added to the current one, therefore
 * missing the solution.
 * 
 */
    vector <int> longest_subsequence; // the LIS
    vector <int> nums;
    int binary_search(int number)
    {
        int start = 0, end = longest_subsequence.size() - 1;
        if(start == end)
        {
            if(number > longest_subsequence[start])
                return start + 1;
            else
                return start;
        }
        while(start < end)
        {
            if(start == end - 1)
            {
                if(number > longest_subsequence[start] && number <= longest_subsequence[end])
                    return end;
                else if(number <= longest_subsequence[start])
                    return start;
                else
                    return end + 1;
            }
            int middle = (start + end + 1) / 2;
            if(longest_subsequence[middle] < number)
                start = middle;
            else
                end = middle;
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int answer = 0;
        if(nums.size())
        {   
            answer = 1;
            longest_subsequence.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++)
            {
                int position = binary_search(nums[i]);
                if(position == longest_subsequence.size())
                    longest_subsequence.push_back(nums[i]);
                else
                    longest_subsequence[position] = nums[i];
                answer = max(answer, position + 1);
            }
        }
        return answer;
    }
};