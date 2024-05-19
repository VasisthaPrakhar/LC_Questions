#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    // int maxScore(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     int mr[n][m],mc[n][m];
    //     for(int i=0;i<n;i++){
    //         int ma=0;
    //         for(int j=m-1;j>=0;j--){
    //             ma=max(grid[i][j],ma);
    //             mr[i][j]=ma;
    //         }
    //     }
    //     for(int j=0;j<m;j++){
    //         int ma=0;
    //         for(int i=n-1;i>=0;i--){
    //             ma=max(mr[i][j],ma);
    //             mc[i][j]=ma;
    //         }
    //     }
    //     int ans=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             int a=-1,b=-1;
    //             if(i+1<n){
    //                 a=mc[i+1][j];
    //             }
    //             if(j+1<m){
    //                 b=mc[i][j+1];
    //             }
    //             if(a>-1 || b>-1){
    //                 ans=max(ans,max(a,b)-grid[i][j]);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    int maxScore(vector<vector<int>>& grid) {
    int ans = INT_MIN;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            int mn = INT_MAX;
            if(i == 0 && j == 0) continue;
            if(i != 0) mn = min(mn, grid[i-1][j]);
            if(j != 0) mn = min(mn, grid[i][j-1]);
            ans = max(ans, grid[i][j] - mn);
            grid[i][j] = min(grid[i][j], mn);
        }
    }
    return ans;
}

};
