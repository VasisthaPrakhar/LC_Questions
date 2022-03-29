class Solution {
public:
    void fun(int &n,int i,string &s){
        if(i==n){
            return;
        }
        int m=s.length();
        string temp="";
        for(int i=0;i<m;i++){
            int cnt=1;
            while(i<m && s[i]==s[i+1]){
                cnt++;
                i++;
            }
            temp+=to_string(cnt)+to_string(s[i]-'0');
        }
        s=temp;
        fun(n,i+1,s);
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s="1";
        fun(n,1,s);
        return s;
    }
};