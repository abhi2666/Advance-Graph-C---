/*
 A = [1, 2, 1, 5]
 output -- > 3 [1, 2, 5]
*/

int Solution::lis(const vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // get result
    return getSubsequence(0, -1, A);
}

/*
Given an integer array nums, return the length of the longest strictly increasing
subsequence.

Subsequence --> A subsequence is an array that can be derived
from another array by deleting some or no elements without changing the
order of the remaining elements.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

*/

/// solution 1

class Solution
{
public:
    int getSubsequence(int currIndex, int prevIndex, vector<vector<int>> &dp, vector<int> &a)
    {
        if (currIndex == a.size())
        {
            return 0;
        }

        if (dp[currIndex][prevIndex + 1] != -1)
            return dp[currIndex][prevIndex + 1];

        // can pick the current element and can even leave it
        int max_len = 0 + getSubsequence(currIndex + 1, prevIndex, dp, a);
        if (prevIndex == -1 || a[currIndex] > a[prevIndex])
        {
            max_len = max(max_len, 1 + getSubsequence(currIndex + 1, currIndex, dp, a));
        }
        
        return dp[currIndex][prevIndex+1] = max_len;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // get result
        return getSubsequence(0, -1, dp, nums);
    }
};



// Solution 2 almost same to solution 1

class Solution
{
public:
    int getAns(vector<int>&arr, int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
    // base condition
    if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
        return getAns(nums,n,0,-1,dp);
    }
};