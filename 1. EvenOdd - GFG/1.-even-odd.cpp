// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> evenOdd(int N, vector<int> arr) {
        // code here
        long long int a=0,b=0;
        for(auto x:arr){
            if(x%2){
                a++;
            }else{
                b++;
            }
        }
        long long int k=(a*(a-1))/2 + (b*(b-1))/2;
        return {k,a*b};
    }
};



// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        vector<long long> ans = ob.evenOdd(N, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends