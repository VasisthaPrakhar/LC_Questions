class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        while(pq.size() && k>0){
            auto t=pq.top();
            pq.pop();
            if(t.first>k){
                k=0;
                pq.push({t.first-k,t.second});
            }else{
                k=k-t.first;
            }
        }
        return pq.size();
    }
};