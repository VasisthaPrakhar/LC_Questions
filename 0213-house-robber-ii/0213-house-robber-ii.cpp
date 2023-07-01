class Solution {
public:
    int fun(vector<int>&a,int st,int e){
        int ans=0,sum=0;
        for(int i=st;i<=e;i++){
            int k=max(ans,sum+a[i]);
            sum=ans;
            ans=k;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        return max(fun(nums,0,n-2),fun(nums,1,n-1));
    }
};