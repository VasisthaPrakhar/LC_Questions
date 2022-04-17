class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        for(int i=total;i>=0;i=i-cost2){
            int k=i/cost1;
            ans+=k+1;
        }
        return ans;
    }
};