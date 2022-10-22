//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int steppingNumbers(int n, int m)
    {
        // Code Here
        queue<int>q;
        for(int i=1;i<10;i++){
            q.push(i);
        }
        int ans=0;
        if(n==0){
            ans++;
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node>=n && node<=m){
                ans++;
            }
            if(node>m){
                continue;
            }
            int p=node%10,k=node*10;
            if(p){
                q.push(k+p-1);
            }
            if(p!=9){
                q.push(k+p+1);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends