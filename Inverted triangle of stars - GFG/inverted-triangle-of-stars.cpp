//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<string> invIsoTriangle(int n) {
        // code here
        vector<string>ans;
        for(int i=0;i<n;i++){
            string a="";
            int j=0,k=0;
            while(k<i){
                a.push_back(' ');
                k++;
            }            
            while(j < ((2*(n-i))-1)){
                a.push_back('*');
                j++;
            }
            k=0;
            while(k<i){
                a.push_back(' ');
                k++;
            }  
            ans.push_back(a);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.invIsoTriangle(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends