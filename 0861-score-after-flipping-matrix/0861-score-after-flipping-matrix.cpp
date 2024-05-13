class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }
                }
            }
        }
        for(int j=0;j<m;j++){
            int c=0,c1=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    c1++;
                }else{
                    c++;
                }
            }
            if(c>=c1){
                for(int i=0;i<n;i++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                ans+=pow(2,m-1-j)*grid[i][j];
            }
            //cout<<endl;
        }
        return ans;
    }
};