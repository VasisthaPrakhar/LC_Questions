class Solution {
public:
    int titleToNumber(string c) {
        int n=c.length(),k=0,ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=(c[i]-'A'+1)*pow(26,k++);
        }
        return ans;
    }
};