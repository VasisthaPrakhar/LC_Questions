class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,-1));
        unordered_map<int,vector<int>>m;
        m[0]={0,1};
        m[1]={1,0};
        m[2]={0,-1};
        m[3]={-1,0};
        int dir=0,i=0,j=0,k=1;
        while(k<=n*n){
            ans[i][j]=k++;
            int ni=i+m[dir][0];
            int nj=j+m[dir][1];
            if(ni>=0 && ni<n && nj>=0 && nj<n && ans[ni][nj]==-1){
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