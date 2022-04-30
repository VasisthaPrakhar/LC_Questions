class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ma=INT_MIN;
        for(auto x:nums){
            sum=max(sum+x,x);
            ma=max(ma,sum);
        }
        return ma;
    }
};