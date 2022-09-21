class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n=in.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(in[0][1]);
        for(int i=1;i<n;i++){
            if(pq.top()>=in[i][0]){
                pq.push(in[i][1]);
            }else{
                pq.pop();
                pq.push(in[i][1]);
            }
        }
        return pq.size();
    }
};