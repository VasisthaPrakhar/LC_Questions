class Solution {
public:
    typedef long long int ll;
    ll fun(int idx,int n,int m,vector<vector<int>>& p,int prev){
        if(idx>=n){
            return 0;
        }
        ll k=0,ans=0;
        for(int j=0;j<m;j++){
            if(prev!=-1){
                k=abs(j-prev);
            }
            ans=max(ans,p[idx][j]-k+fun(idx+1,n,m,p,j));
        }
        return ans;
    }
    long long maxPoints(vector<vector<int>>& p) {
        int n=p.size(),m=p[0].size();
        vector<long long> dp(m, 0);
        
        for(int i = 0; i < m; i++) {
            dp[i] = p[0][i];
        }
        
        for(int r = 1; r < n; r++) {
            vector<long long> leftMax(m, 0), rightMax(m, 0);
            vector<long long> newDp(m, 0);
            
            leftMax[0] = dp[0];
            for(int i = 1; i < m; i++) {
                leftMax[i] = max(leftMax[i-1], dp[i] + i);
            }
            
            rightMax[m-1] = dp[m-1] - (m-1);
            for(int i = m-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], dp[i] - i);
            }
            
            for(int i = 0; i < m; i++) {
                newDp[i] = max(leftMax[i] - i, rightMax[i] + i) + p[r][i];
            }
            
            dp = newDp;
        }
        
        return *max_element(dp.begin(), dp.end());
        //return fun(0,n,m,p,-1);
    }
};