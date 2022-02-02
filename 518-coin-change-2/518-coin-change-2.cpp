class Solution {
public:
    int change(int am, vector<int>& co) {
        vector<int>dp(am+1,0);
        dp[0]=1;
        for(int i=0;i<co.size();i++){
            for(int j=co[i];j<=am;j++){
                dp[j]+=dp[j-co[i]];
            }
        }
        return dp[am];
    }
};