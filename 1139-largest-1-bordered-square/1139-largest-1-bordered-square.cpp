class Solution {
public:
    int dr[8]={0,0,1,-1,1,1,-1,-1};
    int dc[8]={1,-1,0,0,1,-1,1,-1};
    bool check(int row,int col,int n,int m, vector<vector<int>>& mat){
        int ans=0;
        for(int i=0;i<8;i++){
            int r=row,c=col;
            while(r>=0 && r<n && c>=0 && c<m){
                if(mat[r][c]==1){
                    ans++;
                    break;
                }
                r=r+dr[i];
                c=c+dc[i];
            }
        }
        return ans==8;
    }
    bool fun(int r,int c,int k,int n,int m, vector<vector<int>>& grid){
        //cout<<r<<" "<<c<<" "<<k<<endl;
        for(int i=0;i<k;i++){
            //cout<<c-i<<" ";
            if(grid[r][c-i]==0 || grid[r-i][c]==0 || grid[r-i][c-k+1]==0 || grid[r-k+1][c-i]==0){
                return false;
            }
        }
        //cout<<endl;
        return true;
    }
    int largest1BorderedSquare(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>grid=mat;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    if(check(i,j,n,m,mat)){
                        mat[i][j]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                if(ans<dp[i][j]){
                    int z=dp[i][j];
                    while(z>ans){
                        if(fun(i-1,j-1,z,n,m,grid)){
                            ans=z;
                            break;
                        }
                        z--;
                    }
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         int k=min(dp[i-1][j],dp[i][j-1]);
        //         if(mat[i-1][j-1]==0 && i!=1 && i!=n && j!=1 && j!=m){
        //             dp[i][j]=k;
        //         }
        //         if(mat[i-k-1][j-k-1]==1 && dp[i-1][j]>=k && dp[i][j-1]>=k-1 && mat[i-1][j-1]==1){
        //             dp[i][j]=k+1;
        //         }
        //         if(mat[i-1][j-1]==1)
        //             ans=max(ans,dp[i][j]);
        //     }
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<ans<<endl;
        return ans*ans;
    }
};