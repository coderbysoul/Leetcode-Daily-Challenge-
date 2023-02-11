class Solution {
void init(vector<int>col[2][100],vector<vector<int>>&edges,bool flag){
        for(auto &edge:edges)
            col[flag][edge[0]].push_back(edge[1]);
    }
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>edges[2][100];
        vector<int>ans(n,INT_MAX);
        init(edges,redEdges,0);
        init(edges,blueEdges,1);
        queue<pair<int,bool>>pq;pq.push({0,0});pq.push({0,1});
        unordered_set<int>s;
        int lvl = 0;
        while(pq.size()){
            for(int n = pq.size();n;n--){
                auto top = pq.front();pq.pop();
                bool prevCol = top.second;
                ans[top.first] = min(ans[top.first],lvl);
                int parent = top.first;
                for(auto &edge:edges[!prevCol][top.first]){
                    int temp = edge*(prevCol?-1:1);
                    if(s.insert(temp).second)
                    pq.push({edge,!prevCol});
                }
            }
            lvl++;
        }
        for(int i = 0;i<n;i++)
            if(ans[i]==INT_MAX)
                ans[i] = -1;
        return ans;
    }
};