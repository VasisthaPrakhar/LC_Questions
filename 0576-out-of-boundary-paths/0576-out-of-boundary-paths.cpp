class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    typedef long long int ll;
    ll mod=1e9 + 7;
    int dp[51][51][51];
    ll fun(int m,int n,int ma, int r, int c){
        if(ma<0){return 0;}
        if(r<0 || r>=m || c<0 || c>=n ){
            //cout<<r<<" "<<c<<" "<<ma<<endl;
            if(ma>=0){
                return 1;
            }
            return 0;
        }
        if(dp[r][c][ma]!=-1){
            return dp[r][c][ma];
        }
        //cout<<r<<" "<<c<<endl;
        ll res=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            res= (res%mod + fun(m,n,ma-1,nr,nc)%mod)%mod;
        }
        return dp[r][c][ma]=res%mod;
    }
    int findPaths(int m, int n, int ma, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return fun(m,n,ma,sr,sc);
    }
};