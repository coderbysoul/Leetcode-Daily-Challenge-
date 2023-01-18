//https://leetcode.com/problems/maximum-sum-circular-subarray/description/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, 
        maxSum = INT_MIN, 
        curMax = 0, 
        minSum = INT_MAX, 
        curMin = 0;
    for (int it : nums) {
        
        totalSum += it;
        curMax += it;
        curMin += it;
       
        maxSum = max(maxSum, curMax);
        if(curMax < 0)
            curMax = 0;
        
        minSum = min(minSum, curMin);
        if(curMin > 0)
            curMin = 0;
        
    }
    
    return (totalSum == minSum) ? maxSum : max(maxSum, totalSum - minSum);
    }
};