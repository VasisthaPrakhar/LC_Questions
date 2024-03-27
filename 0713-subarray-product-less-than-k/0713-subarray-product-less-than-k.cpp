class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,i=0,ans=0,p=1;
        while(j<n){
            p*=nums[j];
            while(i<=j && p>=k){
                p/=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};