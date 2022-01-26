class Solution {
public:
    unordered_map<int,long long int>m;
    long long int fun(int n){
        if(n==0 || n==1){
            return n;
        }
        if(n==2){
            return 1;
        }
        if(!m.count(n)){
            m[n]=fun(n-1)+fun(n-2)+fun(n-3);
        }
        return m[n];
    }
    int tribonacci(int n) {
        return fun(n);
    }
};