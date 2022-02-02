class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1){
            return cost[0];
        }
        if(n==2){
            return min(cost[1],cost[0]);
        }
        for(int i=2;i<n;i++){
            cost[i]=min(cost[i-1]+cost[i],cost[i-2]+cost[i]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};