class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        int n=trips.size();
        sort(trips.begin(),trips.end(),[](vector<int>&a,vector<int>&b)->bool{
           return a[1]<b[1]; 
        });
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>m(1002,0);
        for(int i=0;i<n;i++){
            while(!pq.empty() && trips[i][1]>=pq.top()){
                cap+=m[pq.top()];
                m[pq.top()]=0;
                pq.pop();
            }
            cout<<cap<<" ";
            if(cap>=trips[i][0]){
                cap=cap-trips[i][0];
                m[trips[i][2]]+=trips[i][0];
                pq.push(trips[i][2]);
            }else{
                return false;
            }
        }
        return true;
    }
};