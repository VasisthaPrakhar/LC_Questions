//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<int>a;
    int fun(int s,int e,int arr[],vector<int>&in, int idx){
        if(s>e){
            return -1;
        }
        int f=lower_bound(in.begin(),in.end(),arr[idx])-in.begin();
        int sz=f-s+1;
        int p=fun(s,f-1,arr,in,idx+1);
        int q=fun(f+1,e,arr,in,idx+sz);
        if(p==-1 && q==-1){
            a.push_back(arr[idx]);
        }
        return 1;
    }
    vector<int> leafNodes(int arr[],int n) {
        // code here
        vector<int>in;
        for(int i=0;i<n;i++){
            in.push_back(arr[i]);
        }
        sort(in.begin(),in.end());
        a.clear();
        fun(0,n-1,arr,in,0);
        return a;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends