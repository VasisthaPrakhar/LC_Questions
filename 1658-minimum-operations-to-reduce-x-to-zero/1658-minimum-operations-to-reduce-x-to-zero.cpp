class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(x>sum){
            return -1;
        }
        if(x==sum){
            return n;
        }
        int t=sum-x,i=0,j=0,ans=-1,k=0;
        while(j<n){
            k+=nums[j];
            while(i<=j && k>t){
                k-=nums[i];
                i++;
            }
            if(k==t)
                ans=max(j-i+1,ans);
            j++;
        }
        return ans==-1?ans:n-ans;
    }
};