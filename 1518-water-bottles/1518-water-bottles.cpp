class Solution {
public:
    int numWaterBottles(int n, int e) {
        int s=0,r=0;
        while(n>=e){
            int q=n/e;
            r=n%e,s+=(e*q);
            n=q+r;
        }
        return s+n;
    }
};