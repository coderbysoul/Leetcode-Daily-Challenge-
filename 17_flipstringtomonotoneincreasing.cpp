//https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        

        int countFlip=0;
        int countOne=0;


        for(auto x: s)
        {
            if(x=='1')
            {
                countOne++;
            }
            else
            {
                countFlip=min(++countFlip,countOne);
            }
        }
        return countFlip;
    }
};