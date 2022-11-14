//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int fun(string &s,string &t,int n,int m,int i,int j){
        if(j==m){
            return 1;
        }
        if(i==n){
            return 0;
        }
        int res=0;
        if(s[i]==t[j]){
            s[i]='@';
            res=fun(s,t,n,m,i+1,j+1);
        }else{
            res=fun(s,t,n,m,i+1,j);
        }
        return res;
    }
    int numberOfSubsequences(string s, string w){
        // code here 
        int n=s.length();
        int m=w.length();
        int res=0;
        for(int i=0;i<n && i<=n-m;i++){
            res+=fun(s,w,n,m,i,0);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends