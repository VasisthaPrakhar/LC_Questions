class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    int n,m,ans=0;
    void dfs(vector<vector<int>>& grid, int r, int c, int cnt) { 
        if (r < 0 or r >= n or c < 0 or c >= m) return;
        if (grid[r][c] == -1) return;
        if(grid[r][c]==2){
            if(cnt==0)
            ans++;
            return;
        }
        int temp=grid[r][c];
        grid[r][c] = -1;
        for (int i = 0; i < 4; i++) { 
            dfs(grid, r + dr[i], c + dc[i],cnt-1);
        }
        grid[r][c]=temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int a,b,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    a=i,b=j;
                }
                else if(grid[i][j]==0){
                    cnt++;
                }
            }
        }
        cnt++;
        dfs(grid,a,b,cnt);
        return ans;
    }
};