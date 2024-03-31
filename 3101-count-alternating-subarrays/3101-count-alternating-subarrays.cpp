class Solution {
public:
    typedef long long int ll;
    ll fun(ll n){
        return (n * (n+1))/2;
    }
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        ll ans=0,s=0,prev=-1;
        int j=0;
        while(j<n){
            ll num=0;
            while(j<n && prev!=nums[j]){
                prev=nums[j];
                num++,j++;
            }
            if(num>0){
                //cout<<num<<" ";
                if(num>1){
                    ans+=fun(num);
                }else{
                    ans+=1;
                }
                prev=-1;
                j--;
            }
            j++;
        }
        return ans;
    }
};