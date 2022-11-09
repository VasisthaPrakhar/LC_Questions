class Solution {
public:
    typedef long long int ll;
    ll fun(int i,int j,vector<int>&nums,int flag){
        if(i>j){
            return 0;
        }
        ll res=0;
        if(!flag){
            res=max(nums[i]+fun(i+1,j,nums,1),nums[j]+fun(i,j-1,nums,1));
        }else{
            res=min(-nums[i]+fun(i+1,j,nums,0),-nums[j]+fun(i,j-1,nums,0));
        }
        return res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        ll t=accumulate(nums.begin(),nums.end(),0LL);
        int i=0,j=n-1,ans=0;
        ll res=fun(i,j,nums,ans);
        cout<<res<<endl;
        return res>=0;
    }
};