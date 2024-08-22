class Solution {
public:
    int findComplement(int num) {
        for(int i=0;i<32;i++){
            long long int k=pow(2,i);
            if(k>num){
                return (k-1)^(long long int)num;
            }
        }
        return 1;
    }
};