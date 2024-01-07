#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    typedef long long int ll;
    map<pair<int,ll>,int>m;
    int fun(int idx,int n,ll dif,int k,vector<int>&nums){
        if(idx==n){
            return 0;
        }
        if(m.find({k,dif})!=m.end()){
            return m[{k,dif}];
        }
        int res=0;
        for(int i=idx;i<n;i++){
            if((ll)nums[i]-nums[k]==dif){
                res+=1+fun(i+1,n,(ll)nums[i]-nums[k],i,nums);
            }
        }
        return m[{k,dif}]=res;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        m.clear();
        ll ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                ans+=fun(j+1,n,(ll)nums[j]-nums[i],j,nums);
            }
        }
        return ans;
    }
};