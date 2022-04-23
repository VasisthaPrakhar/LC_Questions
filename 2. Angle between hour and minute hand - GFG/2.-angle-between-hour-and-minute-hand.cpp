// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getAngle(int h , int m) {
        // code here
        double am=m*6;
        double a=((double)m/60.0)*30.0;
        double ah=h*30.0+a;
        int ans=0;
        if(ah<am){
            ans=min(360.0-(am-ah),am-ah);
        }else{
            ans=min(360.0-(ah-am),ah-am);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}  // } Driver Code Ends