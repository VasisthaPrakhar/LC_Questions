// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    int l=0,r=0,sm=INT_MAX;
	    for(int i=0;i<n-1;i++){
	        if(arr[i]>arr[i+1]){
	            sm=min(arr[i+1],sm);
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i]>sm){
	            l=i;
	            break;
	        }
	    }
	    int big=INT_MIN;
	    for(int i=l;i<n-1;i++){
	        if(arr[i]>arr[i+1]){
	            big=max(arr[i],big);
	        }
	    }
	    for(int i=n-1;i>=l;i--){
	        if(arr[i]<big){
	            r=i;
	            break;
	        }
	    }
	    return {l,r};
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends