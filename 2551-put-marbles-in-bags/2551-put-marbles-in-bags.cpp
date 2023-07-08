class Solution {
public:
    typedef long long int ll;
    long long putMarbles(vector<int>& w, int k) {
        int n=w.size();
        vector<int>a;
        priority_queue<ll>pq_max;
        priority_queue<ll,vector<ll>,greater<ll>>pq_min;
        for(int i=0;i<n-1;i++){
            pq_max.push(w[i]+w[i+1]);
            pq_min.push(w[i]+w[i+1]);
        }
        int z=k-1;
        ll mi=0,ma=0;
        while(z){
            mi+=pq_min.top();
            pq_min.pop();
            ma+=pq_max.top();
            pq_max.pop();
            z--;
        }
        //cout<<ma<<" "<<mi<<endl;
        return ma-mi;
    }
};