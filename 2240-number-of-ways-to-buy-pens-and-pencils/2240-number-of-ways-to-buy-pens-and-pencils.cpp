class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        for(int i=total;i>=0;i=i-cost1){
            int k=i/cost2;
            ans+=k+1;
        }
        return ans;
    }
};