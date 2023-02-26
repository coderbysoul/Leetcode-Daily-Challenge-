class Solution {
public:
    int dp[1009][1009];
    int fun(string word1, string word2,int n,int m){
        if(n==0)return m;
        if(m==0)return n;
        if(dp[n][m]!=-1)
        return dp[n][m];
        if(word1[n-1]==word2[m-1]){
            dp[n][m]=fun(word1,word2,n-1,m-1);
        return dp[n][m];}
        dp[n][m]=1+min(fun(word1,word2,n,m-1),min(fun(word1,word2,n-1,m),fun(word1,word2,n-1,m-1)));
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                dp[i][j] = -1;
            }
        }
        return fun(word1,word2,n,m);
    }
};
