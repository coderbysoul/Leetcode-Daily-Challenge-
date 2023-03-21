//https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long contCount = 0;
        long long subarrays = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                contCount++;
            }
            else{
                subarrays += (contCount*(contCount+1)/2);
                contCount=0;
            }
        }
        // if the last element was 0, we need to calculate for it
        if(contCount>0){
            subarrays += (contCount*(contCount+1)/2);
        }
        return subarrays;
    }
};
