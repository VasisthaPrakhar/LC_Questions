class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int m=n/2;
        map<int,int>mp;
        priority_queue<int>pq;
        for(auto x:arr){
            mp[x]++;
        }
        for(auto x:mp){
            pq.push(x.second);
        }
        int ans=0;
        while(!pq.empty() && n>m){
            n-=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};