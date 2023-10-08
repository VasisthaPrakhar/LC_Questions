class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
		     
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=(dp[i-1][j-1]>0?dp[i-1][j-1]:0)+nums1[i-1]*nums2[j-1];
                int k,l;
                if(i==1){
                    k=INT_MIN;
                }else{
                    k=dp[i-1][j];
                }
                if(j==1){
                    l=INT_MIN;
                }else{
                    l=dp[i][j-1];
                }
                dp[i][j]=max({dp[i][j],k,l});
            }
        }
        return dp[n][m];
    }
};