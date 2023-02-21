class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> M;
        for (int i = 0; i<nums.size(); i++) {
            if (M.find(nums[i]) == M.end()) {
            M[nums[i]] = 1;
        }
        else {
            M[nums[i]]++;
        }
    }
    int t;
    for (auto& it : M) {
        if(it.second==1)
        {
         return it.first;
        }
    }
    return -1;

    }
};