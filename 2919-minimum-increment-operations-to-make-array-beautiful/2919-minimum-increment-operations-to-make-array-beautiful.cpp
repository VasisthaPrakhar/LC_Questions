class Solution {
public:
    typedef long long int ll;
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n=nums.size();
        ll a,b,c;
        a=max(0,k-nums[0]);
        b=max(0,k-nums[1]);
        c=max(0,k-nums[2]);
        for(int i=3;i<n;i++){
            ll mi=min({a,b,c});
            a=b;
            b=c;
            c=max(0,k-nums[i])+mi;
        }
        return min({a,b,c});
    }
};