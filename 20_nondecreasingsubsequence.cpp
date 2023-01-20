//https://leetcode.com/problems/non-decreasing-subsequences/description/

class Solution {
public:
    void solve(vector<int> nums,int pos,vector<int> &temp,set<vector<int>>& st)
    {
        if(pos==nums.size() && temp.size()>=2 && is_sorted(temp.begin(),temp.end()))
        {
            st.insert(temp);
            return;
        }
        if(pos>=nums.size())
            return;
        temp.push_back(nums[pos]);
        solve(nums,pos+1,temp,st);
        temp.pop_back();
        solve(nums,pos+1,temp,st);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> st;
        solve(nums,0,temp,st);
        for(auto it: st)
            ans.push_back(it);
        return ans;
    }
};