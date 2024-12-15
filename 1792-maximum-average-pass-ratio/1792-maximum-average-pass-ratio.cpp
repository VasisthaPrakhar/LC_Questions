class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        int n=c.size();
        priority_queue<vector<double>>pq;
        for(auto x:c){
            double k=(double)x[0]/(double)x[1],k1=((double)x[0]+1)/((double)x[1]+1);
            pq.push({k1-k,(double)x[0],(double)x[1]});
        }
        while(e){
            auto a=pq.top();
            pq.pop();
            a[1]++,a[2]++;
            double k=a[1]/a[2],k1=(a[1]+1)/(a[2]+1);
            pq.push({k1-k,a[1],a[2]});
            e--;
        }
        double sum=0;
        while(!pq.empty()){
            auto a=pq.top();
            sum+=a[1]/a[2];
            pq.pop();
        }
        return sum/(double)n;
    }
};