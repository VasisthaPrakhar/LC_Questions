class Solution {
public:
     int ans;
    bool check(vector<string>&grid,int &r,int &c,int &n){
        for(int i=r;i>=0;i--){
            if(grid[i][c]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;j>=0 && i>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;j<n && i>=0;i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void dfs(int &n, vector<string>&grid,int i){
        if(i==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(check(grid,i,j,n)){
                grid[i][j]='Q';
                dfs(n,grid,i+1);
                grid[i][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>grid(n,s);
        ans=0;
        dfs(n,grid,0);
        return ans;
    }
};