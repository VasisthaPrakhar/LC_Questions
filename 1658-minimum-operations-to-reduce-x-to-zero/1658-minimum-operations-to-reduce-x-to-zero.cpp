class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        int k=sum-x;
        if(k<0){
            return -1;
        }
        if(k==0){return n;}
        int res=0,j=0,i=0,s=0;
        while(j<n){
            s+=nums[j];
            while(i<=j && s>k){
                s-=nums[i];
                i++;
            }
            if(s==k){
                res=max(res,j-i+1);
            }
            j++;
        }
        return res==0?-1:n-res;
    }
};