//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    bool check(map<char,int>&m,int k){
	        if(m.size()==1){
	            return false;
	        }
	        int sum=0;
	        for(auto x:m){
	            sum+=x.second;
	        }
	        for(auto x:m){
	            if(x.second>=sum-k){
	                return false;
	            }
	        }
	        return true;
	    }
		int characterReplacement(string s, int k){
		    // Code here
		    int n=s.length();
		    map<char,int>m;
		    int j=0,i=0,ans=0;
		    while(j<n){
		        m[s[j]]++;
		        while(check(m,k)){
		            m[s[i]]--;
		            if(m[s[i]]==0){
		                m.erase(s[i]);
		            }
		            i++;
		        }
		        ans=max(ans,j-i+1);
		        j++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends