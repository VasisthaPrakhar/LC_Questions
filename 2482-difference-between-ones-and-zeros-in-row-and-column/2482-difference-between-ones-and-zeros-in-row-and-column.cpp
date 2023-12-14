class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>r0(n,0),r1(n,0),co0(m,0),co1(m,0);
        for(int i=0;i<n;i++){
            int c0=0,c1=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c1++;
                }else{
                    c0++;
                }
            }
            r0[i]=c0;
            r1[i]=c1;
        }
        for(int i=0;i<m;i++){
            int c0=0,c1=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    c1++;
                }else{
                    c0++;
                }
            }
            co0[i]=c0;
            co1[i]=c1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=r1[i]-r0[i]+co1[j]-co0[j];
            }
        }
        return grid;
    }
};