class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    pair<int,int>p;
    void dfs(vector<vector<int>>& grid,int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1){
            return;
        }
        grid[x][y]=2;
        if(x>p.first){
            p.first=x;
            p.second=y;
        }else if(x==p.first){
            if(y>p.second){
                p.second=y;
            }
        }
        for(int i=0;i<4;i++){
            dfs(grid,x+dr[i],y+dc[i],n,m);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    p.first=-1,p.second=-1;
                    dfs(land,i,j,n,m);
                    ans.push_back({i,j,p.first,p.second});
                }
            }
        }
        return ans;
    }
};