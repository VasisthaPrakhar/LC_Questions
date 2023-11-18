class Solution {
public:
    typedef long long int ll;
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){return 1;}
        sort(nums.begin(),nums.end());
        ll sum=0,j=0,i=0,ans=0;
        while(j<n){
            sum+=nums[j];
            while(i<j && (((j-i+1)*(ll)nums[j])-sum)>k){
                sum-=nums[i];
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};