class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    void fun(int r,int c,int n,int m,vector<vector<int>>& grid,int &f){
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc]==0){
                continue;
            }
            if(grid[nr][nc]==2){
                continue;
            }
            if(grid[nr][nc]==3){
                f=-1;
            }
            if(f!=-1){
                f++;
            }
            grid[nr][nc]=2;
            fun(nr,nc,n,m,grid,f);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        grid[i][j]=3;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int f=1;
                    grid[i][j]=2;
                    fun(i,j,n,m,grid,f);
                    //cout<<i<<" "<<j<<" "<<f<<" ";
                    if(f!=-1){
                        ans+=f;
                    }
                }
            }
        }
        return ans;
    }
};