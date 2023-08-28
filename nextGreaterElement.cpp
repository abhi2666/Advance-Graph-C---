class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        // sort(nums2.begin(), nums2.end());
        for(auto ele : nums1)
        {
            for(int i = 0; i < nums2.size(); i++)
            {
                if(ele == nums2[i])
                {
                    int j = i + 1;
                    while(j < nums2.size())
                    {
                        if(nums2[j] > nums2[i]){
                            ans.push_back(nums2[j]);
                            break;
                        }
                        j++;
                    }
                    if(j == nums2.size()) ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};