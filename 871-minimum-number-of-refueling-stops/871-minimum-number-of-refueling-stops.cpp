class Solution {
public:
    int minRefuelStops(int ta, int st, vector<vector<int>>& s) {
        int n=s.size();
        int i=st,idx=0,ans=0;
        priority_queue<int>pq;
        while(i<ta){
            while(idx<n && s[idx][0]<=i){
                pq.push(s[idx][1]);
                idx++;
            }
            if(!pq.empty()){
                i+=pq.top();
                pq.pop();
                ans++;
            }else{
                return -1;
            }
        }
        return ans;
    }
};