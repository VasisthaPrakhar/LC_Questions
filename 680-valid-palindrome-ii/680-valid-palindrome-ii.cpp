class Solution {
public:
    bool check(string &s, int f){
        int i,j;
        if(f){
            i=1,j=s.length()-1;
        }else{
            i=0,j=s.length()-2;
        }
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }else{
                i++,j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]!=s[j]){
                string temp=s.substr(i,j-i+1);
                cout<<temp<<" ";
                return check(temp,0) || check(temp,1);
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};