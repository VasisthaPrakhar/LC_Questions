class Solution {
public:
    typedef long long int ll;
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<ll>prev,suf(n,0);
        vector<int>ans;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prev.push_back(sum);
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            suf[i]=sum;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans.push_back(suf[i]-((ll)n*(ll)nums[i]));
            }else if(i==n-1){
                ans.push_back(((ll)n*(ll)nums[i])-prev[i]);
            }else{
                ll a=suf[i]-((ll)(n-i)*(ll)nums[i]);
                ll b=((ll)(i+1)*(ll)nums[i])-prev[i];
                ans.push_back(a+b);
            }
        }
        return ans;
    }
};