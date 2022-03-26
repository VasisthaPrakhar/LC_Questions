class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int ans;
    void bfs_ms(vector<vector<int>>& grid,int &n,int &m,queue<pair<int,int>>&qu){
        while (!qu.empty()) {
            int sz=qu.size();
            while(sz--){
                auto current = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++) { 
                    int R = current.first + dr[i]; 
                    int C = current.second + dc[i];

                    if (R < 0 or R >= n or C < 0 or C >= m) continue;
                    if (grid[R][C] == 1) continue;
                    grid[R][C] = 1;
                    qu.push({R, C});
                }
            }
            ans++;
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        ans=-1;
        bfs_ms(grid,n,m,q);
        return ans==0?-1:ans;
    }
};