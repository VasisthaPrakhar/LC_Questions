class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    
    void dfs(vector<vector<int>>& grid, int n, int m,int r,int c,queue<vector<int>>&q){
        if(r<0 ||r>=n || c<0 || c>=m || grid[r][c]==0 || grid[r][c]==2){return;}
        grid[r][c]=2;
        q.push({r,c,0});
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            dfs(grid,n,m,nr,nc,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,n,m,i,j,q);
                    f=true;
                    break;
                }
            }
            if(f){break;}
        }
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int dist=q.front()[2];
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 ||nr>=n || nc<0 || nc>=m || grid[nr][nc]==2){
                    continue;
                }
                if(grid[nr][nc]==1){
                    return dist;
                }else{
                    grid[nr][nc]=2;
                    q.push({nr,nc,dist+1});
                }
            }
        }
        return -1;
    }
};