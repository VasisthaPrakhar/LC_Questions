class Solution {
public:
    int dr[3]={1,1,1};
    int dc[3]={-1,0,1};
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int mi=INT_MAX;
                for(int k=0;k<3;k++){
                    int r=i+dr[k];
                    int c=j+dc[k];
                    if(c<0 || c>=n || r<0 || r>=n){
                        continue;
                    }
                    mi=min(mi,mat[r][c]);
                }
                mat[i][j]+=mi;
            }
        }
        int ans=*min_element(mat[0].begin(),mat[0].end());
        return ans;
    }
};