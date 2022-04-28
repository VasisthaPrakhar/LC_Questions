class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int last=-1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    last=i;
                    break;
                }
            }
            if(last!=-1){
                break;
            }
        }
        if(last==-1){
            return;
        }
        for(int i=0;i<last;i++){
            int flag=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    mat[last][j]=0;
                    flag=1;
                }
            }
            if(flag){
                for(int j=0;j<m;j++){
                    mat[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(mat[last][i]==0){
                for(int j=0;j<n;j++){
                    mat[j][i]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            mat[last][i]=0;
        }
    }
};