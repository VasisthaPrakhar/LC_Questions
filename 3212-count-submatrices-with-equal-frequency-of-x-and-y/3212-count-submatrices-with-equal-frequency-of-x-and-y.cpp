class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(m));
        vector<vector<pair<int,int>>>dp1(n,vector<pair<int,int>>(m));
        for(int i=0;i<n;i++){
            int cx=0,cy=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    cx++;
                }
                if(grid[i][j]=='Y'){
                    cy++;
                }
                dp[i][j]={cx,cy};
            }
        }
        for(int j=0;j<m;j++){
            int cx=0,cy=0;
            for(int i=0;i<n;i++){
                cx+=dp[i][j].first;
                cy+=dp[i][j].second;
                dp1[i][j]={cx,cy};
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<"{"<<dp1[i][j].first<<", "<<dp1[i][j].second<<"}"<<" ";
                if(dp1[i][j].first>0 && dp1[i][j].first==dp1[i][j].second){
                    ans++;
                }
            }
            //cout<<endl;
        }
        return ans;
    }
};