//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int fun(int n, int b){
      string s;
      while(n){
          int k=n%b;
          if(k<10){
              s.push_back(k+'0');
          }else{
              k-=10;
              char ch=k+'A';
              s.push_back(ch);
          }
          n/=b;
      }
      return s.length();
  }
    string baseEquiv(int n, int m){
        // code here
        for(int i=2;i<33;i++){
            if(fun(n,i)==m){
                return "Yes";
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends