class Solution {
public:
    //unordered_map<string,int>dp;
    int dp[501][26][502];
    int fun(int idx,int k,vector<int>&a, int n,int prev){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][k][prev]!=-1){
            return dp[idx][k][prev];
        }
        int res=0,x=0,y=0;
        if(prev==0){
            x=1+fun(idx+1,k,a,n,a[idx]);
            y=fun(idx+1,k,a,n,prev);
        }else{
            if(a[idx]!=prev){
                if(k>0)
                    x=1+fun(idx+1,k-1,a,n,a[idx]);   
            }else{
                x=1+fun(idx+1,k,a,n,a[idx]);
            }
            y=fun(idx+1,k,a,n,prev);
        }
        res=max(x,y);
        return dp[idx][k][prev]=res;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int j=1;
        for(auto &x:mp){
            for(auto &y:x.second){
                nums[y]=j;
            }
            j++;
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,k,nums,n,0);
    }
};