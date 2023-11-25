class Solution {
public:
    typedef long long int ll;
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<ll>prev(n,0),suf(n,0);
        vector<int>ans(n,0);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prev[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            suf[i]=sum;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=suf[i]-((ll)n*(ll)nums[i]);
            }else if(i==n-1){
                ans[i]=((ll)n*(ll)nums[i])-prev[i];
            }else{
                ll a=suf[i]-((ll)(n-i)*(ll)nums[i]);
                ll b=((ll)(i+1)*(ll)nums[i])-prev[i];
                ans[i]=a+b;
            }
        }
        return ans;
    }
};