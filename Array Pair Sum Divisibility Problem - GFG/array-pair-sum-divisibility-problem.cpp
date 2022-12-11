//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n%2){
            return false;
        }
        map<int,int>m;
        for(int i=0;i<n;i++){
            int j=nums[i]%k;
            if(m.find(k-j)!=m.end()){
                m[k-j]--;
                if(m[k-j]==0){
                    m.erase(k-j);
                }
            }else{
                m[j]++;
            }
        }
        if(m.size()==1){
            if(m.count(0)){
                return true;
            }else{
                return false;
            }
        }
        return m.size()==0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends