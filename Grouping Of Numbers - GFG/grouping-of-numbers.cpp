//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        // code here
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]%k]++;
        }
        int ans=0;
        if(m[0]>0){
            ans+=1;
        }
        for(int i=1,j=k-1;i<=j;i++,j--){
            if(i==j && m[i]>0){
                ans+=1;
            }else{
                ans+=max(m[i],m[j]);
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends