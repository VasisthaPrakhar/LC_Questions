class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long int ans=0,sum=0;
        for(int i=0;i<n;i++){
            // if(nums[i]>nums[i-1]){
            //     int d=nums[i]-nums[i-1];
            //     nums[i]-=((d+1)/2);
            //     nums[i-1]+=((d+1)/2);
            // }
            // if(nums[i-1]<ma){
            //     int k=(ma-nums[i-1]);
            //     nums[i-1]+=k;
            //     nums[i]-=k;
            // }
            // cout<<ma<<" "<<nums[i]<<" "<<nums[i-1]<<endl;
            // ma=max({ma,nums[i],nums[i-1]});
            sum+=nums[i];
            ans=max((sum+i)/(i+1),ans);
        }
        return ans;
    }
};