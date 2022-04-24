// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++



class Solution
{
   public:
    int minMoves(int target)
    {
       //Write your code here
       target = abs(target);
        
        // start from N = 1;
        long long int  N = 1;
        
        // while condition is not met, do iterate
        while(!(target <= N*(N+1)/2 && (target %2) == ((N*(N+1)/2) %2)))
            N++;
        
        return N;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    Solution ob;  
	    int ans=ob.minMoves(n);
	    cout << ans << endl;
	}
	return 0;
}  // } Driver Code Ends