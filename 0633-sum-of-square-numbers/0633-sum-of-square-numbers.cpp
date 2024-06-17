class Solution {
public:
    typedef long long int ll;
    bool isPerfectSquare(long double x){
        if (x >= 0) {
            long long sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        for(ll i=0;i*i<=c;i++){
            long double a=c-(i*i);
            if(isPerfectSquare(a)){
                cout<<a<<endl;
                return true;
            }
        }
        return false;
    }
};