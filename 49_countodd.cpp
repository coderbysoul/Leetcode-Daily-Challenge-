class Solution {
public:
    int countOdds(int low, int high) {
        int r=0;
        if(low&1){
            r++;
            low++;
        }
        if(high&1){
            r++;
            high--;
        }
        r+=(high-low)/2;
        
        return r;
    }
};
