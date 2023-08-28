/*

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


approach --> for this problem we can find the prefix product till a neg comes and we can 
also we can find the suffix from the end until we find the same neg no. and from then we 
will take the max of both.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffixProd = 1, prefixProd = 1;
        int ans = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            // if you encounter zero then restart the prefix/sufix
            if(prefixProd == 0) prefixProd = 1;
            if(suffixProd == 0) suffixProd = 1;
            prefixProd = prefixProd * nums[i];
            suffixProd = suffixProd * nums[n-1-i];
            ans = max(ans, max(prefixProd, suffixProd));
        }
        return ans;
    }
};
