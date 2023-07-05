class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int j=0,i=0,k=0,ma=0;
        while(j<n){
            if(nums[j]==0){
                k++;
            }
            while(i<=j && k>1){
                if(nums[i]==0){
                    k--;
                }
                i++;
            }
            int res=j-i+1-k;
            if(k==0){
                res--;
            }
            ma=max(ma,res);
            j++;
        }
        return ma;
    }
};