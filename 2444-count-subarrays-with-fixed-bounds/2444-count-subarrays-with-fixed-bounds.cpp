class Solution {
public:
    typedef long long int ll;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n=nums.size();
        ll mi=INT_MAX,ma=INT_MIN;
        int j=0,p=-1,q=-1;
        ll ans=0;
        vector<int>arr;
        arr.push_back(-1);
        while(j<n){
            if(nums[j]<minK || nums[j]>maxK){
                arr.push_back(j);
                p=-1;
                q=-1;
            }
            if(nums[j]==minK){
                q=j;
            }
            if(nums[j]==maxK){
                p=j;
            }
            if(p!=-1 && q!=-1){
                ans+=max(0LL,(ll)min(p,q)-arr.back()); 
            }
            j++;
        }
        return ans;
    }
};