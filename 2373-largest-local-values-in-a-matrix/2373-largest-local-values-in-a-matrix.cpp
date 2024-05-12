class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int ma=0;
                for(int r=i;r<i+3;r++){
                    for(int c=j;c<j+3;c++){
                        ma=max(ma,grid[r][c]);
                    }
                }
                ans[i][j]=ma;
            }
        }
        return ans;
    }
};