// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void non_repeating(int n, vector<int> &a){
        // code here
        set<int>st;
        vector<int>s;
        for(int i=0;i<n;i++){
            if(!st.count(a[i])){
                st.insert(a[i]);
                s.push_back(a[i]);
            }
        }
        for(auto x:s){
            cout<<x<<" ";
        }
    }
};


// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        obj.non_repeating(N, A);
        cout << "\n";
    }
}  // } Driver Code Ends