class Solution {
public:
    typedef long long int ll;
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto x:nums){
            pq.push(x);
        }
        ll ans=0;
        while(!pq.empty() && k--){
            int z=pq.top();
            ans+=z;
            pq.pop();
            pq.push(ceil((double)z/3.0));
        }
        return ans;
    }
};