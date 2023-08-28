/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Approach --> recursive way to try all the possible operations in teh required space..
*/

class Solution {
public:
    int getDistance(int n, int m, vector<vector<int>>&dp, string& word1, string& word2)
    {
        if(n < 0) return m + 1;
        if(m < 0) return n + 1;

        if(dp[n][m] == -1) return dp[n][m];
        // check if both the chars are equal..don't do anything
        if(word1[n]==word2[m]) return dp[n][m] = getDistance(n-1, m-1, dp, word1, word2);

        return dp[n][m] =  1 + min(getDistance(n, m-1, word1, word2) , min(getDistance(n-1, m, word1, word2), getDistance(n-1, m-1, word1, word2)));
    }


    int minDistance(string word1, string word2) {
        int n = word1.size()-1;
        int m = word2.size()-1;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return getDistance(n, m, word1, word2);
    }
};