class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<int>res(n,1);
        // for(int i=0;i<n;i++){
        //     auto it=lower_bound(res.begin(),res.end(),nums[i]);
        //     if(it-res.begin()==res.size()){
        //         res.push_back(nums[i]);
        //     }else{
        //         *it=nums[i];
        //     }
        // }
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    res[i]=max(res[i],1+res[j]);
                }
            }
            ans=max(ans,res[i]);
        }
        return ans;
    }
};