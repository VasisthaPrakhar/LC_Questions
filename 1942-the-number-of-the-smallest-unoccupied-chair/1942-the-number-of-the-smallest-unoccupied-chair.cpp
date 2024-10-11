class Solution {
public:
    int smallestChair(vector<vector<int>>& t, int target){
        int n=t.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<int>s;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({t[i][0],i});
            s.insert(i);
        }
        sort(v.begin(),v.end());
        for(auto x:v){
            while(!pq.empty() && pq.top().first<=x.first){
                s.insert(pq.top().second);
                pq.pop();
            }
            int seat=*s.begin();
            pq.push({t[x.second][1],seat});
            s.erase(seat);
            //cout<<x.first<<" "<<t[x.second][1]<<" "<<seat<<"\t"<<x.second<<endl;
            if(x.second==target){
                return seat;
            }
        }
        return n;
    }
};