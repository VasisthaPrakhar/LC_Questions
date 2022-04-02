class Solution {
public:
    bool check(string &s, int i, int j){
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
                //string temp=s.substr(i,j-i+1);
                //cout<<temp<<" ";
                return check(s,i+1,j) || check(s,i,j-1);
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};