class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<double>pre,suf(n,0);
        double sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
            pre.push_back(sum1);
            suf[n-i-1]=sum2;
            sum2+=nums[n-i-1];
        }
        int ans=INT_MAX,z=floor(sum1/(double)n),idx=0;
        for(int i=0;i<n-1;i++){
            double a=floor(pre[i]/(double)(i+1));
            double b=floor(suf[i]/(double)(n-i-1));
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