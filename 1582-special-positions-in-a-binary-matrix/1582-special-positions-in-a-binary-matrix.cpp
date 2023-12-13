class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size(),ans=0;
        vector<int>a(n,-1);
        for(int i=0;i<n;i++){
            int c=0,k=-1;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    c++;
                    k=j;
                }
            }
            if(c==1){
                a[i]=k;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                int c=0;
                for(int j=0;j<n;j++){
                    if(mat[j][a[i]]==1){
                        c++;
                    }
                }
                if(c==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};