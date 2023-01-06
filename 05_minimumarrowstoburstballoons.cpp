//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

//greedy algorithm--> for problems which require minimum result or maximum result,i.e.,for optimisation problem
bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
    }
class Solution {
   
    

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int arrow=1;
        int end=points[0][1];
        for(int x=1;x<points.size();x++)
        {
            if(points[x][0]>end)
            {
                arrow++;
                end=points[x][1];
            }
        }
        return arrow;
    }
};
