// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

typedef long long int ll;
class Solution{
  public:
  bool fun(ll &t, ll &k){
      string s=to_string(k);
      int n=s.length();
      ll d=pow(10,n);
      ll ans=t%d +t/d;
      return ans==k;
  }
    vector<int> kaprekarN(int n){
        //Code Here
        vector<int>ans;
        ans.push_back(1);
        n--;
        ll k=4;
        while(n){
            ll t=k*k;
            if(fun(t,k)){
                ans.push_back(k);
                n--;
            }
            k++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution ob;
        vector<int> ans = ob.kaprekarN(n);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends