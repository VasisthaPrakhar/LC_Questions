class TreeAncestor {
private: vector<vector<int>>dp;
public:
    TreeAncestor(int n, vector<int>& par) {
        int r=16;
        dp.resize(r,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=par[i];
        }
        //Consider Each row as the ith Power of 2 and you are calculating its parent just like exponent squaring in network security
        for(int i=1;i<r;i++){
            for(int j=0;j<n;j++){
                if(dp[i-1][j]==-1){
                    dp[i][j]=-1;
                }else{
                    dp[i][j]=dp[i-1][dp[i-1][j]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans=node,pow=0;
        while(k){
            if(ans==-1){break;}
            if(k&1){
                ans=dp[pow][ans];
            }
            pow++;
            k=k>>1;
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */