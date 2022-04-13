class Solution{
public:
vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m1=mat[0].size();
        vector<int>ans;
        unordered_map<int,vector<int>>m;
        m[0]={0,1};
        m[1]={1,0};
        m[2]={0,-1};
        m[3]={-1,0};
        int dir=0,i=0,j=0,k=1;
        while(ans.size()<n*m1){
            ans.push_back(mat[i][j]);
            mat[i][j]=-101;
            int ni=i+m[dir][0];
            int nj=j+m[dir][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m1 && mat[ni][nj]!=-101){
                i=ni,j=nj;
            }else{
                dir=(dir+1)%4;
                i=i+m[dir][0];
                j=j+m[dir][1];
            }
        }
        return ans;
    }
};