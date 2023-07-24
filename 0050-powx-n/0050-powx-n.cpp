class Solution {
public:
    double myPow(double x, int n) {
         if(n==0) return 1.0;
        long long int no=n;
        if(no<0){
            no = -1 * no;
            x = 1.0 / x;
        }

        double result = 1;
        while(no>0){
            if(no%2==1){
                result = result*x;
                no--;
            }
            x = x*x;
            no = no/2;
        }
        return result;
    }
};