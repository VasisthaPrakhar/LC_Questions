class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n=r.size(),m=c.size(),k;
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                k=r[i]<c[j]?r[i]:c[j];
                r[i]-=k,c[j]-=k,ans[i][j]=k;
            }
        }
        return ans;
    }
};