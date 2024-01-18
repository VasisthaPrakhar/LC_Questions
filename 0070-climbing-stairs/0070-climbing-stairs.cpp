class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2,temp;
        if(n==1){
            return a;
        }
        for(int i=2;i<n;i++){
            temp=a;
            a=b;
            b=a+temp;
        }
        return b;
        
    }
};