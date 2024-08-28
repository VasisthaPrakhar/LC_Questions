class Solution {
public:
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& grid2,int x,int y,int n,int m,bool &flag){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1){
            return;
        }
        grid[x][y]=2;
        if(grid2[x][y]!=1){
            flag=false;
        }
        for(int i=0;i<4;i++){
            dfs(grid,grid2,x+dr[i],y+dc[i],n,m,flag);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    bool flag=true;
                    dfs(grid2,grid1,i,j,n,m,flag);
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};