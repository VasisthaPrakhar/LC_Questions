// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
    bool check(vector<string>&grid,int &r,int &c,int &n){
        for(int i=r;i>=0;i--){
            if(grid[i][c]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void dfs(int &n,vector<string>&grid,int i,vector<int>&res){
        if(i==n){
            ans.push_back(res);
            return;
        }
        for(int j=0;j<n;j++){
            if(check(grid,i,j,n)){
                grid[i][j]='Q';
                res.push_back(j+1);
                dfs(n,grid,i+1,res);
                res.pop_back();
                grid[i][j]='.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        string s(n,'.');
        vector<string>grid(n,s);
        vector<int>res;
        dfs(n,grid,0,res);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends