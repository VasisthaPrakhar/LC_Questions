class Solution {
public:
    int maxPoints(vector<vector<int>>& po) {
        int n=po.size();
        if(n==1){
            return 1;
        }
        int ans=2;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            map<double,int>m;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(po[j][0]==po[i][0]){
                        m[INT_MAX]++;
                        pq.push({m[INT_MAX],i});
                    }else{
                        double s=(double)(po[j][1]-po[i][1])/(double)(po[j][0]-po[i][0]);
                        m[s]++;
                        pq.push({m[s],i});
                    }
                }
            }
        }
        ans=max(ans,pq.top().first+1);
        return ans;
    }
};