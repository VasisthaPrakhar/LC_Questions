class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        int n=c.size();
        if(n==1){
            return c[0];
        }else if(n==2){
            return c[0]>c[1]?c[1]:c[0];
        }else{
            int one=c[0],temp;
            int two=c[1];
            for(int i=2;i<n;i++){
                temp=two;
                two=c[i]+min(one,two);
                one = temp;
            }
            return one<two?one:two;
        }
    }
};