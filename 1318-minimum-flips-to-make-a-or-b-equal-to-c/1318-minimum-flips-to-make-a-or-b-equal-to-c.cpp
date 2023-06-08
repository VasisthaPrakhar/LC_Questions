class Solution {
public:
    string bi(int n){
        string s="";
        while(n){
            int r=n%2;
            n=n/2;
            s.push_back(r+'0');
        }
        reverse(s.begin(),s.end());
        return s;
    }
    void fun(string &s,int n){
        string s1(n,'0');
        s=s1+s;
    }
    int minFlips(int a, int b, int c) {
        string s1=bi(a),s2=bi(b),s=bi(c);
        int n=s.length(),n1=s1.length(),n2=s2.length();
        int k=max({n,n1,n2});
        fun(s,k-n);
        fun(s1,k-n1);
        fun(s2,k-n2);
        int ans=0;
        for(int i=0;i<k;i++){
            if(s[i]=='1' && (s1[i]=='0' && s2[i]=='0')){
                ans++;
            }else if(s[i]=='0' && (s1[i]=='1' || s2[i]=='1')){
                if(s1[i]=='1' && s2[i]=='0'){
                    ans++;
                }else if(s1[i]=='0' && s2[i]=='1'){
                    ans++;
                }else{ans+=2;}
            }
        }
        return ans;
    }
};