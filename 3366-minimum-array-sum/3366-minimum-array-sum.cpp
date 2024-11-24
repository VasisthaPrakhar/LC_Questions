class Solution {
public:
    typedef long long int ll;
    int dp[101][101][101];
    ll fun(int idx,int n, vector<int>& nums,int k,int op1,int op2){
        if(idx==n){return 0;}
        if(dp[idx][op1][op2]!=-1){
            return dp[idx][op1][op2];
        }
        ll res=INT_MAX;
        if(op1>0){
            int z=round((double)nums[idx]/2.0);
            res=min(res,z+fun(idx+1,n,nums,k,op1-1,op2));
            if(z>=k && op2>0){
                res=min(res,(z-k)+fun(idx+1,n,nums,k,op1-1,op2-1));
            }
        }
        if(op2>0 && nums[idx]>=k){
            res=min(res,(nums[idx]-k)+fun(idx+1,n,nums,k,op1,op2-1));
            if(op1>0){
                int z=round((double)(nums[idx]-k)/2.0);
                res=min(res,z+fun(idx+1,n,nums,k,op1-1,op2-1));
            }
        }
        res=min(res,nums[idx]+fun(idx+1,n,nums,k,op1,op2));
        return dp[idx][op1][op2]=res;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,n,nums,k,op1,op2);
    }
};