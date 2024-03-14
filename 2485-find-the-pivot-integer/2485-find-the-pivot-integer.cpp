class Solution {
public:
    long long int fun(int n){
        return (n*(n+1))/2;
    }
    int pivotInteger(int n) {
        long long int s=fun(n);
        for(int i=1;i<=n;i++){
            if(fun(i)==((double)(s+i)/2.0)){
                return i;
            }
        }
        return -1;
    }
};