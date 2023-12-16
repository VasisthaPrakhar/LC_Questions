class Solution {
public:
    int dp[1001][1001];
    bool isvowel(char ch){
        return (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u');
    }
    int fun(string &s, int k, vector<int>&v,vector<int>&c, int i, int j){
        if(j<=i){
            return 0;
        }
        if(dp[i][j]!=-1){
            return 0;
        }
        int a=0,x=0,y=0;
        if(i==0){
            x=v[j];
            y=c[j];
        }else{
            x=v[j]-v[i-1];
            y=c[j]-c[i-1];
        }
        if(x==y && (x*y)%k==0){
            a=1;
            cout<<i<<" "<<j<<endl;
        }
        return dp[i][j]=a+fun(s,k,v,c,i+1,j)+fun(s,k,v,c,i,j-1);
    }
    int beautifulSubstrings(string s, int k) {
        int n=s.length();
        vector<int>v(n,0),c(n,0);
        int a=0,b=0;
        for(int i=0;i<n;i++){            
            if(isvowel(s[i])){
                a++;
            }else{
                b++;
            }
            v[i]=a;
            c[i]=b;
        }
        memset(dp,-1,sizeof(dp));
        return fun(s,k,v,c,0,n-1);
    }
};