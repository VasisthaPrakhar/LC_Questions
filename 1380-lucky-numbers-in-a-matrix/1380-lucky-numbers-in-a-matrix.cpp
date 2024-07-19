class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int>row,col,ans;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int mi=INT_MAX;
            for(int j=0;j<m;j++){
                mi=min(mi,mat[i][j]);
            }
            row.push_back(mi);
        }
        for(int i=0;i<m;i++){
            int mi=INT_MIN;
            for(int j=0;j<n;j++){
                mi=max(mi,mat[j][i]);
            }
            col.push_back(mi);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==col[j] && mat[i][j]==row[i]){
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};