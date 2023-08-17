class Solution {
public:
     Solution(){                                                                  
          std::ios_base::sync_with_stdio(0);                                       
          std::cin.tie(0);
    }
    int n,m;
    int dr[4] = {1, -1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>> qu;
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    qu.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
         while (!qu.empty()) {
            auto current = qu.front();
            qu.pop();
             int res=ans[current.first][current.second];
            for (int i = 0; i < 4; i++) { 
                    int R = current.first + dr[i]; 
                    int C = current.second + dc[i];
                    if (R < 0 or R >= n or C < 0 or C >= m) continue;
                    if(grid[R][C]==1 && ans[R][C]==INT_MAX){
                        ans[R][C]=ans[current.first][current.second]+1;
                        qu.push({R,C});
                    }
                }
        }
        return ans;
    }
};