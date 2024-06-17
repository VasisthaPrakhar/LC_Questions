class Solution {
public:
    typedef long long int ll;
    bool isPerfectSquare(double x){
        if (x >= 0) {
            int sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        for(ll i=0;i*i<=c;i++){
            double a=c-(i*i);
            if(isPerfectSquare(a)){
                return true;
            }
        }
        return false;
    }
};