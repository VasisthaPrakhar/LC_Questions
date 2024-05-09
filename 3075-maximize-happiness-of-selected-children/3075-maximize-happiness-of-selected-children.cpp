class Solution {
public:
    typedef long long int ll;
    long long maximumHappinessSum(vector<int>& h, int k) {
        ll ans=0,n=h.size();
        priority_queue<ll>pq;
        for(int i=0;i<n;i++){
            pq.push(h[i]);
        }
        int no=k;
        while(k && pq.size() && pq.top()-(no-k)>0){
            ans+=pq.top()-(no-k);
            k--;
            pq.pop();
        }
        return ans;
    }
};