class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2){return false;}
        long long int sum=nums[0];
        unordered_map<int,int>mp;
        mp[(sum+k)%k]=0;
        for(int i=1;i<n;i++){
            sum+=nums[i];
            if(nums[i]==0){
                if(nums[i-1]==0){
                    return true;
                }else{continue;}
            }
            if((sum+k)%k==0){
                return true;
            }
            if(mp.find((sum+k)%k)!=mp.end() && i-mp[(sum+k)%k]>1){
                return true;
            }
            mp[(sum+k)%k]=i;
        }
        return false;
    }
};