
class Solution {
public:
    int dp(vector<int>&jd,int idx,int day,int &d, vector<vector<int>>&memo,vector<int>&upmax,int n){
        if(day==d){
            return upmax[idx];
        }
        if(memo[idx][day]==-1){
            int ans=INT_MAX,ma=0;
            for(int i=idx;i<n-(d-day);i++){
                ma=max(ma,jd[i]);
                ans=min(ans,ma+dp(jd,i+1,day+1,d,memo,upmax,n));
            }
            memo[idx][day]=ans;
        }
        return memo[idx][day];
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(d>n){
            return -1;
        }
        vector<int>upmax(n);
        int ma=0;
        for(int i=n-1;i>=0;i--){
            ma=max(ma,jd[i]);
            upmax[i]=ma;
        }
        vector<vector<int>>memo(n,vector<int>(d+1,-1));
        return dp(jd,0,1,d,memo,upmax,n);
    }
};
