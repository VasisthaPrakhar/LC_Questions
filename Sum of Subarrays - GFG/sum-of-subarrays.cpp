// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        vector<long long>v;
        long long mod=1000000007;
        int a0=n-2;
        for(int i=0;i<n;i++){
            long long j=(i)<(n-i-1)?i:(n-i-1);
            long long k=(j*(2*a0+(j-1)*(-2))/2);
            v.push_back(n+k);
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans%mod+(v[i]*a[i])%mod)%mod;
        }
        return ans%1000000007;
    }
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}
  // } Driver Code Ends