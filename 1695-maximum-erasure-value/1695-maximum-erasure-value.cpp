class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        int i=0,j=0,ans=0,sum=0;
        while(j<n){
            m[nums[j]]++;
            sum+=nums[j];
            while(i<=j && m[nums[j]]>1){
                m[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};