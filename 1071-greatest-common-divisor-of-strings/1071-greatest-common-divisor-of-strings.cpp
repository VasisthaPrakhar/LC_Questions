class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        string t1=s1,t2=s2;
        while(s1.length()<=m){
            s1+=t1;
        }
        while(s2.length()<=n){
            s2+=t2;
        }
        int k=min((int)s1.length(),(int)s2.length());
        //cout<<n<<" "<<s2.substr(0,k)<< " "<<m;
        if(s1.substr(0,k)==s2.substr(0,k)){
            return s1.substr(0,__gcd(n,m));
        }else{
            return "";
        }
    }
};