class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>directions={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.empty() || q.size()==n*n){
            return -1;
        }
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[x,y]=q.front();
                q.pop();
                for(auto& d : directions){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(nx >= 0 && nx<n && ny>=0 && ny<n && grid [nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
            steps++;
        }
        return steps - 1;
    }
};