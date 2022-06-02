class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>a(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j]=mat[j][i];
            }
        }
        return a;
    }
};