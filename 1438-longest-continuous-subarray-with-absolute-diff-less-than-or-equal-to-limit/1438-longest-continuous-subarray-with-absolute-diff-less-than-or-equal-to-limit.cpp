class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int>mi;
        map<int,int,greater<int>>ma;
        int n=nums.size(),j=0,i=0,ans=0;
        while(j<n){
            ma[nums[j]]++;
            mi[nums[j]]++;
            while(i<=j && ma.begin()->first - mi.begin()->first > limit){
                mi[nums[i]]--;
                if(mi[nums[i]]==0){
                    mi.erase(nums[i]);
                }
                ma[nums[i]]--;
                if(ma[nums[i]]==0){
                    ma.erase(nums[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};