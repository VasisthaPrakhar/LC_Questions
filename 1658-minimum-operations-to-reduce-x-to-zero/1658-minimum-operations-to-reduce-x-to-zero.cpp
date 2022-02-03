class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(x>sum){
            return -1;
        }
        if(x==sum){
            return n;
        }
        int t=sum-x,ans=-1,i=0,j=0,temp=0;
        while(j<n && i<=j){
            temp+=nums[j];
            while(i<=j && temp>t){
                temp-=nums[i];
                i++;
            }
            if(temp==t){
                ans=max(j-i+1,ans);
            }
            j++;
        }
        return ans==-1?-1:n-ans;
    }
};