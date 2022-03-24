class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        if(n==k){
            return sum/(double)k;
        }
        int i=0,j=k;
        double ma=sum;
        while(j<n){
            sum=sum+nums[j++];
            sum=sum-nums[i++];
            ma=max(ma,sum);
        }
        return ma/(double)k;
    }
};