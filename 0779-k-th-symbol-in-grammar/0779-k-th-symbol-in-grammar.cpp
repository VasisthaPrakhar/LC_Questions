class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        int z=kthGrammar(n-1,ceil((double)k/2.0));
        if(z==1){
            if(k%2==0){
                return 0;
            }else{
                return 1;
            }
        }else{
             if(k%2==0){
                return 1;
            }else{
                return 0;
            }
        }
    }
};