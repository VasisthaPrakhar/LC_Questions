class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mr[n][m],mc[n][m];
        for(int i=0;i<n;i++){
            int ma=0;
            for(int j=m-1;j>=0;j--){
                ma=max(grid[i][j],ma);
                mr[i][j]=ma;
            }
        }
        for(int j=0;j<m;j++){
            int ma=0;
            for(int i=n-1;i>=0;i--){
                ma=max(mr[i][j],ma);
                mc[i][j]=ma;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=-1,b=-1;
                if(i+1<n){
                    a=mc[i+1][j];
                }
                if(j+1<m){
                    b=mc[i][j+1];
                }
                if(a>-1 || b>-1){
                    ans=max(ans,max(a,b)-grid[i][j]);
                }
            }
        }
        return ans;
    }
};