class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }else if(x<10){
            return true;
        }else{
            long long y=x,ans=0;
            while(y){
                ans=ans*10 + y%10;
                y=y/10;
            }
            if(ans==x){
                return true;
            }
        }
        return false;
    }
};