class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>>a(m,vector<int>(n,0));
        for(auto &x:g){
            a[x[0]][x[1]]=1;
        }
        for(auto &x:w){
            a[x[0]][x[1]]=2;
        }
        vector<vector<int>>b=a;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(a[i][j-1]==1 && a[i][j]==0){
                    a[i][j]=1;
                }
            }
            for(int j=n-2;j>=0;j--){
                if(a[i][j+1]==1 && a[i][j]==0){
                    a[i][j]=1;
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                if(b[i-1][j]==1 && b[i][j]==0){
                    b[i][j]=1;
                }
            }
            for(int i=m-2;i>=0;i--){
                if(b[i+1][j]==1 && b[i][j]==0){
                    b[i][j]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0 && b[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};