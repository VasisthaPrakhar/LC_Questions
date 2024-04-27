class Solution {
public:
    typedef long long int ll;
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<int,int>row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    col[i]++;
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=(row[i]-1) * (col[j]-1);
                }
            }
        }
        return ans;
    }
};