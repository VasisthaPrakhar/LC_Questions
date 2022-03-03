// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here
        int n=A.size();
        long long x=0,res1=0,l=0,r=0,res2=0;
        while(r<n){
            x+=A[r];
            while(x>R){
                x-=A[l];
                l++;
            }
            res1+=r-l+1;
            r++;
        }
        r=0,l=0,x=0;
        while(r<n){
            x+=A[r];
            while(x>=L){
                x-=A[l];
                l++;
            }
            res2+=r-l+1;
            r++;
        }
        long long ans= res1-res2;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}    // } Driver Code Ends