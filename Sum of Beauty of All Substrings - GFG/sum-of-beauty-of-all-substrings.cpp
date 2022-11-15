//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n=s.length();
        long long int ans=0;
        for(int i=0;i<n;i++){
            vector<int>a(26,0);
            for(int j=i;j<n;j++){
                int mi=INT_MAX,ma=0;
                a[s[j]-'a']++;
                for(auto x:a){
                    ma=max(x,ma);
                    if(x!=0){
                        mi=min(x,mi);
                    }
                }
                ans+=ma-mi;
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends