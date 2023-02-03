//https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
       string mat[numRows][s.size()]; 
       int row=0,col=0,in=0;
       string ans="";
       while(in<s.size())
       {
          while(row<numRows&&in<s.size())
          {
            mat[row++][col]=s[in++];
          }
          row=max(row-2,0);
          while(row>0&&in<s.size())
          {
              mat[row--][++col]=s[in++];
          }
          col++;
       }
       for(int i=0;i<numRows;i++)
       {
           for(int j=0;j<s.size();j++)
           {
               ans+=mat[i][j];
           }
       }
       return ans; 
    }
};