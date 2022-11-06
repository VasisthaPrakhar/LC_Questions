//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int sum)
    {
        // code here
         vector<int>a={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 },ans;
         for(int i=9;i>=0;i--){
             if(sum>=a[i]){
                 sum-=a[i];
                 ans.push_back(a[i]);
                 i++;
             }
             if(sum==0){
                 return ans;
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends