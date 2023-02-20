class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]<target)
            l=mid+1;
            else
            h=mid-1;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<target && nums[i+1]>target)
            return i+1;
        }
        if(target<nums[0])
        return 0;

        return h+1;
    }
    }