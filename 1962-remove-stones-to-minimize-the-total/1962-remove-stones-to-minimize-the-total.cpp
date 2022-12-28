class Solution {
public:
    #define ll long long int
    int minStoneSum(vector<int>& p, int k) {
        ll sum=0;
        priority_queue<int>pq;
        for(auto x:p){
            sum+=x;
            pq.push(x);
        }
        while(k-- && !pq.empty()){
            int z=pq.top();
            pq.pop();
            int x=z/2;
            sum-=x;
            pq.push(z-x);
        }
        
        return sum;
    }
};