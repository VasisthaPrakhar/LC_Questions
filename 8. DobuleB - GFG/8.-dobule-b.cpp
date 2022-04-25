// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    long long DoubleB(int n,int a[],long long b)
    {
       //write your code here
       int i=0;
       while(i<n){
           if(a[i]==b){
               b*=2;
           }
           i++;
       }
        return b;
    }
};

// { Driver Code Starts.



int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,b;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i<n; i++)cin >> arr[i];
	    cin >> b;
	    Solution obj;
	    cout << obj.DoubleB(n,arr,b) << "\n";

	}

}
  // } Driver Code Ends