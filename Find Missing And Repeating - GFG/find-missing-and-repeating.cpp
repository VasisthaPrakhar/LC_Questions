//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
typedef long long int ll;
    ll su(ll n){
        return (n*(n+1))/2;
    }
    int *findTwoElement(int *arr, int n) {
        // code here
        ll sum=0,sum1=su(n);
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        ll dif=sum-sum1;
        int a,b;
        for(int i=0;i<n;i++){
            int k=abs(arr[i])-1;
            arr[k]=arr[k]*-1;
            if(arr[k]>0){
                a=k+1;
                break;
            }
        }
        int *ans=new int[2];
        ans[0]=a;
        ans[1]=a-dif;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends