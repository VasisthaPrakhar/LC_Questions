class Solution {
public:
    int change(int am, vector<int>& co) {
        if(am==0){
            return 1;
        }
        vector<int>dp(am+1,0);
        dp[0]=1;
        for(int i=0;i<co.size();i++){
            for(int j=1;j<=am;j++){
                if(co[i]<=j){
                    dp[j]+=dp[j-co[i]];
                }
            }
        }
        return dp[am];
    }
};