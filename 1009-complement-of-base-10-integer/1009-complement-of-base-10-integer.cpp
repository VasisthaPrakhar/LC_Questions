class Solution {
public:
int fun(int n)
{
    int binaryNum[32];
    int i = 0,ans=0;
    while (n > 0) {
        binaryNum[i] = 1-(n % 2);
        n = n / 2;
        i++;
    }
    for (int j=0;j<i;j++){
        ans+=binaryNum[j]*pow(2,j);
    }
    return ans;
}
 
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        return fun(n);
    }
};