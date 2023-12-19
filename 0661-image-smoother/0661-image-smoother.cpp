class Solution {
public:
    int dr[8]={0,0,1,-1,1,1,-1,-1};
    int dc[8]={1,-1,0,0,1,-1,1,-1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=img[i][j],p=1;
                for(int k=0;k<8;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr<0 ||nr>=n || nc<0 || nc>=m){continue;}
                    p++;
                    sum+=img[nr][nc];
                }
                ans[i][j]=sum/p;
            }
        }
        return ans;
    }
};