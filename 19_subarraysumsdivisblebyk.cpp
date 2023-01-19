//https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int n=nums.size();
        int count=0,totalSum=0;
        mp[0]++; 
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
            int rem=(totalSum%k+k)%k; 
            count+=mp[rem]++; 
        }
        return count;
    }
};