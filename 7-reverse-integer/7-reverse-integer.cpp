class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        int si=0;
        if(x<0){
            si=1;
            x=abs(x);
        }
        while(x){
            ans=ans*10 + x%10;
            x=x/10;
        }
        if(si==1){
            ans=ans*-1;
        }
        if(ans>2147483647 || ans<-2147483648)
        {
            return 0;    
        }        
        return ans;
    }
};