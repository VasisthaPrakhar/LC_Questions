class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int one_back = 1;
        int two_back = 0;
        
        for (int i = 2; i <= n; i++) {
            int temp = one_back;
            one_back += two_back;
            two_back = temp;
        }
        
        return one_back;
    }
};