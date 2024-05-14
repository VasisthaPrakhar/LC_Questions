class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int fun(vector<vector<int>>& grid, int n, int m,int r,int c){
        int ans=grid[r][c];
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]==0){continue;}
            int t=grid[nr][nc];
            grid[nr][nc]=0;
            ans=max(ans,t+fun(grid,n,m,nr,nc));
            grid[nr][nc]=t;
        }
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ans=max(ans,fun(grid,n,m,i,j));
                }
            }
        }
        return ans;
    }
};