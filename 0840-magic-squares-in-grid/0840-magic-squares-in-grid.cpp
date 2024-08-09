class Solution {
public:
    bool check(vector<vector<int>>&grid){
        int sum=0;
        set<int>st;
        for(int i=0;i<3;i++){
            int s=0;
            for(int j=0;j<3;j++){
                s+=grid[i][j];
                if(grid[i][j]>9 || grid[i][j]<1){
                    return false;
                }
                st.insert(grid[i][j]);
            }
            if(sum==0){
                sum=s;
            }else{
                if(sum!=s){
                    return false;
                }
            }
        }
        for(int j=0;j<3;j++){
            int s=0;
            for(int i=0;i<3;i++){
                s+=grid[i][j];
                if(grid[i][j]>9){
                    return false;
                }
                st.insert(grid[i][j]);
            }
            if(sum==0){
                sum=s;
            }else{
                if(sum!=s){
                    return false;
                }
            }
        }
        if(st.size()!=9){
            return false;
        }
        int s1=grid[0][0]+grid[1][1]+grid[2][2],s2=grid[0][2]+grid[1][1]+grid[2][0];
        if(s1!=sum){return false;}
        if(s2!=sum){return false;}
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mat(3,vector<int>(3,0));
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                mat[0][0]=grid[i][j];
                mat[0][1]=grid[i][j+1];
                mat[0][2]=grid[i][j+2];
                mat[1][0]=grid[i+1][j];
                mat[1][1]=grid[i+1][j+1];
                mat[1][2]=grid[i+1][j+2];
                mat[2][0]=grid[i+2][j];
                mat[2][1]=grid[i+2][j+1];
                mat[2][2]=grid[i+2][j+2];
                if(check(mat)){
                    ans++;
                }
            }
        }
        return ans;
    }
};