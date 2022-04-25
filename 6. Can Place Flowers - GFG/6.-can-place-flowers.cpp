// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int canPlaceFlowers(vector<int>&f, int n)
    {
        //Your code here
        int m=f.size(),cnt=0;
        if(f[0]==0 && f[1]==0){
            cnt++;
            f[0]=1;
        }
        for(int i=1;i<m-1;i++){
            if(f[i-1]==0 && f[i+1]==0 && f[i]==0){
                cnt++;
                f[i]=1;
                i++;
            }
        }
        if(f[m-1]==0 && f[m-2]==0){
            cnt++;
        }
        //cout<<cnt<<" ";
        return cnt>=n;
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
	    vector<int>flowerbed(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> flowerbed[i];
	    }
	    int N;
	    cin >> N;
	    Solution ob;
	    int ans = ob.canPlaceFlowers(flowerbed, N);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends