class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int mi=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i]-mi;
        }
        return ans;
    }
};