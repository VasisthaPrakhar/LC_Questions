// { Driver Code Starts
//Initial Template for C++
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    long long findJumps(long long n,long long k)
    {
       //write your code here
       if(n<k){
           return n;
       }else if(n>k){
           return n/k + (n%k);
       }else{
           return 1;
       }
        
    }
};

// { Driver Code Starts.



int main() {
	int t;
	cin >> t;
	while(t--){
	    long long n, k;
	    cin >> n >> k;
	    Solution obj;
	    cout << obj.findJumps(n,k) << "\n";

	}

}
  // } Driver Code Ends