class Solution {
public:
    int longestValidParentheses(string s) {
        int c=0,ans=0,len=0,ans1=0,ans2=0,c1=0,len1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            {
                c++;
            }
            else{
                if(c<=0){
                    len = 0;
                }
                else{
                    c--;
                    len = len + 2;
                    
                    if(c==0){
                        ans1 = max(ans1,len);
                    }
                }
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')')
            {
                c1++;
            }
            else{
                if(c1<=0){
                    len1 = 0;
                }
                else{
                    c1--;
                    len1 = len1 + 2;
                    
                    if(c1==0){
                        ans2 = max(ans2,len1);
                    }
                }
            }
        }
        ans = max(ans1,ans2);
        return ans;
    }
};