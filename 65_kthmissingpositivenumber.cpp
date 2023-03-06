class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == target) return true;
            else if(arr[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, cnt = 0;
        while(cnt != k && ++lo) {
            if(!search(arr, lo)) cnt++;
        }
        return lo; 
    }
};
