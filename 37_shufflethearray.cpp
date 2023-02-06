//https://leetcode.com/problems/shuffle-the-array/description/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int i,j;
        for( i=0, j=n;i<n;i++,j++){
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        }

        return ans;
    }
};