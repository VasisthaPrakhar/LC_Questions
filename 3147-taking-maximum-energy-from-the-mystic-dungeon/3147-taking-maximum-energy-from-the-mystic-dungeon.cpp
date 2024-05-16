class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int n=a.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            if(i-k<0){
                dp[i]=a[i];
            }else{
                dp[i]=max(a[i],a[i]+dp[i-k]);
            }
        }
        int ma=INT_MIN;
        for(int i=n-1;i>+0 && k;i--,k--){
            ma=max(dp[i],ma);
        }
        return ma;
    }
};