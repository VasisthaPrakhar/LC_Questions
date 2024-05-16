class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int n=a.size();
        vector<int>dp(n);
        int ma=INT_MIN;
        for(int i=0;i<n;i++){
            if(i-k<0){
                dp[i]=a[i];
            }else{
                dp[i]=max(a[i],a[i]+dp[i-k]);
            }
            if(i+k>=n){
                 ma=max(dp[i],ma);
            }
        }
        return ma;
    }
};