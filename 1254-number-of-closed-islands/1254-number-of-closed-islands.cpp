class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    void dfs(vector<vector<int>>& grid,int &n,int &m,int r,int c,int &f){
        if(r<0 || r>=n || c<0 || c>=m){return;}
        if(grid[r][c]!=0){
            if(grid[r][c]==3){
                f=0;
            }
            return;
        }
        grid[r][c]=2;
        for(int i=0;i<4;i++){
            dfs(grid,n,m,r+dr[i],c+dc[i],f);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]!=1){
                        grid[i][j]=3;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int f=1;
                    dfs(grid,n,m,i,j,f);
                    if(f)
                    ans++;
                }
            }
        }
        return ans;
    }
};