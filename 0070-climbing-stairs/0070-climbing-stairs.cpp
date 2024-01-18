class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int a=1,b=2,temp;
        for(int i=2;i<n;i++){
            temp=a;
            a=b;
            b=a+temp;
        }
        return b;
        
    }
};