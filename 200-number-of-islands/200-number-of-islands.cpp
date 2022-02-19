class Solution {
public:
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    void dfs(vector<vector<char>>& grid,int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!='1'){
            return;
        }
        grid[x][y]='v';
        for(int i=0;i<4;i++){
            dfs(grid,x+dr[i],y+dc[i],n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};