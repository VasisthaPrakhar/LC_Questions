class Solution {
public:
    typedef long long int ll;
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        vector<ll>pre,suf(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            if(sum<=nums[i]){
                sum+=nums[i];
            }else{
                sum=nums[i];
            }
            pre.push_back(sum);
        }
        sum=nums[n-1];
        suf[n-1]=sum;
        for(int i=n-2;i>=0;i--){
            if(sum>=nums[i]){
                sum+=nums[i];
            }else{
                sum=nums[i];
            }
            suf[i]=sum;
        }
        ll ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,suf[i]+pre[i]-nums[i]);
        }
        return ans;
    }
};