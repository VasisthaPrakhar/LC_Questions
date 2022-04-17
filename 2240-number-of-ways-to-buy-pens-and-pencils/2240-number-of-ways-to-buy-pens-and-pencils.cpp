class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        if(cost1>total && cost2>total){
            return 1;
        }
        if(cost1>cost2){
            for(int i=total;i>=0;i=i-cost1){
                int k=i/cost2;
                ans+=k+1;
            }
        }else{
            for(int i=total;i>=0;i=i-cost2){
                int k=i/cost1;
                ans+=k+1;
            }
        }
        return ans;
    }
};