//https://leetcode.com/problems/best-team-with-no-conflicts/description/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> team;
        for(int i=0;i<scores.size();i++)
        {
            team.push_back({scores[i],ages[i]});
        }
        sort(team.begin(),team.end());
        vector<vector<int>> dp(scores.size(),vector<int>(1001,0));
        return fun(dp,team,0,0);
    }
    int fun(vector<vector<int>>& dp,vector<pair<int,int>>& team,int i,int max_age)
    {
        if(i>=team.size())
            return 0;
        if(dp[i][max_age]!=0)
            return dp[i][max_age];
        
        int t=fun(dp,team,i+1,max_age);
        if(team[i].second>=max_age)
        {
            t=max(t,team[i].first+fun(dp,team,i+1,team[i].second));
        }
        return dp[i][max_age]=t;
    }
};