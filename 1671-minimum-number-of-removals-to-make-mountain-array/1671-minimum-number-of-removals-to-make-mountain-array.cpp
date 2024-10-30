class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0),suf(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    pre[i]=max(pre[i],1+pre[j]);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i])
                    suf[i]=max(suf[i],1+suf[j]);
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            //cout<<pre[i]<<" ";
            if(pre[i]>0 && suf[i]>0)
                ans=max(ans,pre[i]+suf[i]+1);
        }
        return n-ans;
    }
};