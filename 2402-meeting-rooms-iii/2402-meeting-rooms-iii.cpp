class Solution {
public:
    typedef long long int ll;
    typedef pair<ll,pair<ll,ll>> PII;
    class Compare {
    public:
        bool operator()(PII below, PII above)
        {
            if (below.first > above.first) {
                return true;
            }
            else if (below.first == above.first
                     && below.second.second > above.second.second) {
                return true;
            }

            return false;
        }
    };
    int mostBooked(int n, vector<vector<int>>& me) {
        sort(me.begin(),me.end());
        priority_queue<PII,vector<PII>,Compare>pq,temp;
        int i=0;
        while(i<n){
            pq.push({0,{0,i}});
            i++;
        }
        for(auto x:me){
            while(!pq.empty() && pq.top().first<=x[0]){
                temp.push(pq.top());
                pq.pop();
            }
            while(!temp.empty()){
                pq.push({0,{temp.top().second.first,temp.top().second.second}});
                temp.pop();
            }
            auto y=pq.top();
            pq.pop();
            ll a =y.first<=x[0]?x[1]:y.first+x[1]-x[0];
            pq.push({a,{y.second.first+1,y.second.second}});
        }
        // while (!pq.empty()) {
        //     cout << pq.top().first << " " << pq.top().second.first<<" "<<pq.top().second.second
        //          << "\n";
        //     pq.pop(); // heapify happens
        // }
        ll ma=0,ans=INT_MAX;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(ma<x.second.first){
                ma=x.second.first;
                ans=x.second.second;
                //cout<<ma<<endl;
            }else if(ma==x.second.first){
                ans=min(ans,x.second.second);
            }
        }
        return ans;
    }
};