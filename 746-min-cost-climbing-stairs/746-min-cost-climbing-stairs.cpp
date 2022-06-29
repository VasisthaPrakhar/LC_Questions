class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        int n=c.size();
        if(n==1){
            return c[0];
        }
        if(n==2){
            return min(c[0],c[1]);
        }
        int one=c[0],two=c[1];
        for(int i=2;i<n;i++){
            int temp=two;
            two=c[i]+min(one,two);
            one=temp;
        }
        return min(one,two);
    }
};