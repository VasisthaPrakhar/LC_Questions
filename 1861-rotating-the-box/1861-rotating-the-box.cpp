class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=m-1,k=m-1;j>=0;j--){
                if(mat[i][j]=='#'){
                    while(k>=j){
                        if(mat[i][k]=='.'){
                            mat[i][k]='#';
                            mat[i][j]='.';
                            break;
                        }
                        k--;
                    }
                }else if(mat[i][j]=='*'){
                    k=j-1;
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                ans[i][n-j-1]=mat[j][i];
            }
            //cout<<endl;
        }
        return ans;
    }
};