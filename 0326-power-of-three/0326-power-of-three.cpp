class Solution {
public:
    bool isPowerOfThree(int n) {
        double k = (log10(n)/log10(3));
        return n>0 && k==(int)k;
    }
};