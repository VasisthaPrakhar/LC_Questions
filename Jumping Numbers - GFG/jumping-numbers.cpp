//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef long long int ll;
    int fun(ll x){
        string s=to_string(x);
        return s.length();
    }
    void bfs(ll f,int n,ll x,ll &ans){
        queue<ll>q;
        q.push(f);
        while(!q.empty()){
            ll node=q.front();
            q.pop();
            if(node<=x){
                ans=max(ans,node);
            }
            if(fun(node)==n){
                continue;
            }
            if(node%10==0){
                q.push(node*10+1);
            }else if(node%10==9){
                q.push(node*10+8);
            }else{
                ll r=node%10;
                ll k=node*10+r;
                q.push(k+1);
                q.push(k-1);
            }
        }
    }
    long long jumpingNums(long long x) {
        // code here
        if(x<=10){
            return x;
        }
        int n=fun(x);
        ll ans=-1;
        for(ll i=1;i<10;i++){
            bfs(i,n,x,ans);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends