//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        // multiset<int>ma;
        // for(int i=0;i<k;i++){
        //     ma.insert(arr[i]);
        // }
        // vector<int>ans;
        // auto it=ma.end();
        // it--;
        // ans.push_back(*it);
        // int j=k,i=0;
        // while(j<n){
        //     auto t=ma.find(arr[i++]);
        //     ma.erase(t);
        //     ma.insert(arr[j++]);
        //     auto it=ma.end();
        //     it--;
        //     ans.push_back(*it);
        // }
        // return ans;
        deque<int>q;
        vector<int>ans;
        // for(int i=0;i<k;i++){
        //     if(q.empty()){
        //         q.push_back(i);
        //     }else{
        //         while(!q.empty() && arr[q.back()]<arr[i]){
        //             q.pop_back();
        //         }
        //         q.push_back(i);
        //     }
        // }
        //ans.push_back(arr[q.front()]);
        int j=0;
        while(j<n){
            if(q.empty()){
                q.push_back(j);
            }else{
                while(!q.empty() && arr[q.back()]<arr[j]){
                    q.pop_back();
                }
                q.push_back(j);
            }
            if(!q.empty() && q.front()<=j-k){
                q.pop_front();
            }
            if(j>=k-1)
                ans.push_back(arr[q.front()]);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends