class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m=nums.size();
        long long int miss=1,i=0,ans=0;
        while(miss<=n){
            if(i<m && nums[i]<=miss){
                miss+=nums[i];
                i++;
            }else{
                miss*=2;
                ans++;
            }
        }
        return ans;
    }
};