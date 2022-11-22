//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int n=nums.size();
	    int ans=0;
	    for(int i=1;i<n-1;i++){
	        int j=i-1,k=i+1,cl=0,cr=0;
	        while(j>=0){
	            if(nums[j]<nums[i]){
	                cl++;
	            }
	            j--;
	        }
	        while(k<n){
	            if(nums[k]>nums[i]){
	                cr++;
	            }
	            k++;
	        }
	        ans+=cl*cr;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends