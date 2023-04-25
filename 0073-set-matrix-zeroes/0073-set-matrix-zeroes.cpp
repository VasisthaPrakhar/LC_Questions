class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
      int m=mat[0].size(),last=-1;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(mat[i][j]==0){
                  last=i;
              }
          }
      }
      if(last==-1){
          return;
      }
      for(int i=0;i<last;i++){
          int f=0;
          for(int j=0;j<m;j++){
              if(mat[i][j]==0){
                  mat[last][j]=0;
                  f=1;
              }
          }
          if(f==1){
              for(int k=0;k<m;k++){
                  mat[i][k]=0;
              }
          }
      }
      for(int i=0;i<m;i++){
          if(mat[last][i]==0){
              for(int j=0;j<n;j++){
                  mat[j][i]=0;
              }
          }
          mat[last][i]=0;
      }
        // cout<<last<<endl;
        // for(int i=0;i<m;i++){
        //     mat[last][i]=0;
        // }
    }
};