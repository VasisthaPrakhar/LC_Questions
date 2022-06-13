class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& c) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int x=grid[i][j];
                int mi=INT_MAX;
                for(int k=0;k<m;k++){
                    mi=min(mi,c[x][k]+grid[i+1][k]);
                }
                grid[i][j]+=mi;
                //cout<<grid[i][j]<<" ";
            }
            //cout<<endl;
        }
        for(int i=0;i<m;i++){
            ans=min(ans,grid[0][i]);
        }
        return ans;
    }
};