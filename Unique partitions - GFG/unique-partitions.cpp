//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
	void fun(int n,vector<int>&a){
	    if(n==0){
	        ans.push_back(a);
	        return;
	    }
	    if(n<0){
	        return;
	    }
	    int up=n;
	    if(a.size()>0){
	        up=a.back();
	    }
	    //cout<<up<<" ";
	    for(int i=up;i>=1;i--){
            a.push_back(i);
	        fun(n-i,a);
	        a.pop_back();
	    }
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        ans.clear();
        vector<int>a;
        fun(n,a);
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
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends