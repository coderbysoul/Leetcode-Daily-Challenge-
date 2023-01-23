//https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);

        for(vector<int>&presentTrust : trust)
        {
            int trusted=presentTrust[1];
            int trusting=presentTrust[0];

            indegree[trusted]++;
            outdegree[trusting]++;
        }

        for(int i=1;i<=n;i++)
        if(indegree[i]==n-1 && outdegree[i]==0)
        return i;

        return -1;
    }
};

