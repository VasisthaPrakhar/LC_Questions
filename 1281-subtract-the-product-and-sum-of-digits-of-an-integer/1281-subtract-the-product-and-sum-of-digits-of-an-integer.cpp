class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0,k;
        while(n){
            k=n%10;
            p=p*k;
            s+=k;
            n=n/10;
        }
        return p-s;
    }
};