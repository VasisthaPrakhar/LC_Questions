class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma=0,n=nums.size();
        int ans=0,len,j=0;
        for(int i=0;i<n;i++){
            ma=max(ma,nums[i]);
        }
        while(j<n){
            if(ma==nums[j]){
                int len=0;
                while(j<n && ma==nums[j]){
                    len++;
                    j++;
                }
                j--;
                ans=max(len,ans);
            }
            j++;
        }
        return ans;
    }
};