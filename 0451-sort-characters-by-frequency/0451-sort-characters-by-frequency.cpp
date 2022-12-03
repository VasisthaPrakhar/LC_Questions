class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        string ans="";
        while(!pq.empty()){
            auto [x,y]=pq.top();
            while(x--){
                ans.push_back(y);
            }
            pq.pop();
        }
        return ans;
    }
};