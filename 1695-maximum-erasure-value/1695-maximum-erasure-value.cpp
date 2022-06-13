class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        int j=0,i=0,sum=0,ans=0;
        while(j<n){
            sum+=nums[j];
            m[nums[j]]++;
            while(i<j && m[nums[j]]>1){
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