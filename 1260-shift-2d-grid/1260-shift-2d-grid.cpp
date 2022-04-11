class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        while(k--){
            vector<int>a;
            a.push_back(grid[n-1][m-1]);
            for(int i=0;i<n-1;i++){
                a.push_back(grid[i][m-1]);
            }
            for(int j=0;j<m;j++){
                int x=0;
                for(int i=0;i<n;i++){
                    swap(a[x++],grid[i][j]);
                }
            }
        }
        return grid;
    }
};