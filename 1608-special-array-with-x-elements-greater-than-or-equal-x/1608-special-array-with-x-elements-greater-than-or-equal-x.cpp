class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(n-i<=nums[i]){
                if(i>0 && nums[i-1]>=n-i){continue;}
                return n-i;
            }
        }
        return -1;
    }
};