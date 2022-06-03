class NumMatrix {
    private:
    vector<vector<int>>sum;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>s(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mat[i-1][j-1];
            }
        }
        sum=s;
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return sum[r2+1][c2+1]-sum[r1][c2+1]-sum[r2+1][c1]+sum[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */