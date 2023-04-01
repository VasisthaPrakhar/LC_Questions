class Solution {
public:
    typedef long long int ll;
    int mod=1e9+7;
    int dp[51][51][11];
    int fun(vector<vector<int>>&a,int k,int n,int m,int r,int c){
        if(dp[r][c][k]!=-1){
            return dp[r][c][k];
        }
        if(k==0){
            if(a[r][c]==0){
                return 0;
            }else{
                return 1;
            }
        }
        ll res=0;
        for(int i=r+1;i<n;i++){
            if(a[i][c]>=k && a[r][c]>a[i][c]){
                res=(res%mod+fun(a,k-1,n,m,i,c)%mod)%mod;
            }
        }
        for(int i=c+1;i<m;i++){
            if(a[r][i]>=k && a[r][c]>a[r][i]){
                res=(res%mod+fun(a,k-1,n,m,r,i)%mod)%mod;
            }
        }
        return dp[r][c][k]=res;
    }
    int ways(vector<string>& p, int k) {
        int n=p.size();
        int m=p[0].length();
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int z=i;z<n;z++){
                   if(p[z][j]=='A'){
                       a[i][j]+=1;
                   }
                }
                if(j!=m-1){
                    a[i][j]+=a[i][j+1];
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return fun(a,k-1,n,m,0,0);
    }
};