class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>pre,suf(n,0);
        long long int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
            pre.push_back(sum1);
            suf[n-i-1]=sum2;
            sum2+=nums[n-i-1];
        }
        long long int ans=LLONG_MAX,z=sum1/n,idx=0;
        for(int i=0;i<n-1;i++){
            int a=pre[i]/(i+1);
            int b=suf[i]/(n-i-1);
            int k=abs(a-b);
            if(ans>k){
                ans=k;
                idx=i;
            }
        }
        if(ans>z){
            idx=n-1;
        }
        return idx;
    }
};