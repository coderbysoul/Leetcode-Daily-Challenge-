//https://leetcode.com/problems/detect-capital/description/

class Solution {
public:
    bool detectCapitalUse(string word) {

        int capCnt = 0;
        int n = word.size();

        if( n==1 ) return true;

        for( auto &it : word ){
            if( it>='A' && it<='Z' ) capCnt++;
        } 

        // "USA"
        if( capCnt>=2 && capCnt==n ) return true;
        // "Google"
        else if( capCnt == 1 && ( word[0]>='A' && word[0]<='Z' ) ) return true;
        // "leetcode"
        else if( capCnt == 0 && n>=1 ) return true;

        return false;
    }
};