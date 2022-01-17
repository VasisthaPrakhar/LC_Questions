class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0,ans1=INT_MIN,ans2=INT_MAX;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            ans1=max(ans1,sum);
            if(sum<0){sum=0;}
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            ans2=min(ans2,sum);
            if(sum>0){
                sum=0;
            }
        }
        return max(abs(ans1),abs(ans2));
    }
};