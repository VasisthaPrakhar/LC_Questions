class Solution {
public:
    int dc[4]={0,0,1,-1};
    int dr[4]={1,-1,0,0};
    void dfs(int r,int c,vector<vector<int>>& grid,int co,int &n, int &m){
        int real=grid[r][c];
        grid[r][c]=2000;
        int f=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m){
                continue;
            }else if(grid[nr][nc]!=co){
                if(grid[nr][nc]<1001){
                    f++;
                }   
                continue;
            }else{
                dfs(nr,nc,grid,co,n,m);
            }
        }
        if(r==0 || c==0 || r==n-1 || c==m-1 || f>0){
            grid[r][c]=1001;
        }else{
            grid[r][c]=real;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        int c=grid[row][col];
        dfs(row,col,grid,c,n,m);
        for(auto &x:grid){
            for(auto &y:x){
                if(y==1001){
                    y=color;
                }
            }
        }
        return grid;
    }
};