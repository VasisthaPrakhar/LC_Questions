class Solution {
public:
    int solve(vector<int>&nums){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if((i-cnt)%2==0){
                int j=i;
                while(i+1<n && nums[i+1]==nums[j]){
                    cnt++;
                    i++;
                }
            }
        }
        if((n-cnt)%2){
            cnt++;
        }
        return cnt;
    }
    int minDeletion(vector<int>& nums) {
        return solve(nums);
    }
};