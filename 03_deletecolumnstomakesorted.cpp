//https://leetcode.com/problems/delete-columns-to-make-sorted/description/ 

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del=0;
        int row=strs.size();
        int col=strs[0].size();
        
        for(int j=0;j<col;j++)
        {
            for(int i=0;i<row-1;i++)
            {
                if((int)strs[i][j]>(int)strs[i+1][j])
                {
                    del++;
                    break;
                }
            }
        }
        
        return del;
    }
};