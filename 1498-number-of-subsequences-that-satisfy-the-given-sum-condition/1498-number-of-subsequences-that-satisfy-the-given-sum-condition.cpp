class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>sum;
        sum.push_back(1);
        for(int i=1;i<n;i++){            
            int s=sum.back();
            s = (s%mod*2)%mod;
            sum.push_back(s);
        }
        int i=0,j=0,ans=0;
        while(i<n){
            int k=target-nums[i];
            if(k>nums[i]){
                auto f=upper_bound(nums.begin(),nums.end(),k);
                if((f-nums.begin())>=n){
                    j=n-1;
                }
                else{
                    j=f-nums.begin();
                    if(nums[j]>k){j--;}
                }
            }
            else if(k==nums[i]){
                 auto f=upper_bound(nums.begin(),nums.end(),k);
                j=f-nums.begin();
                j--;
            }else{
                i++;
                continue;
            }
            if(nums[i]+nums[j]<=target){
                ans= (ans%mod + (sum[j-i])%mod);
            }
            i++;
        }
        return ans%mod;
    }
};