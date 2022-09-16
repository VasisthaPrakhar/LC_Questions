static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int dr[4] = {1, -1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1};
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>> qu){
        int n=grid.size();
        int m=grid[0].size();
        int ans=-1;
        while (!qu.empty()) { 
            int s=qu.size();
            while(s--){
                auto current = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++) { 
                    int R = current.first + dr[i]; 
                    int C = current.second + dc[i];

                    if (R < 0 or R >= n or C < 0 or C >= m) continue; 
                    if (grid[R][C] != 1) continue;
                    
                    grid[R][C] = 2; 
                    qu.push({R, C});
                }
            }
            ans++;
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<int,int>> qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    qu.push({i,j});
                }
            }
        }
        ans=max(bfs(grid,qu),ans);
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};