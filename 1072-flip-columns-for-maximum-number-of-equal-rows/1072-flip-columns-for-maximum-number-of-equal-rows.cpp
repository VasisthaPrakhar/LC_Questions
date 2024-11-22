class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size(),ans=1;
        map<string,int>mp;
        for(int i=0;i<n;i++){
            string a="",b="";
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    a.push_back('0');
                    b.push_back('1');
                }else{
                    a.push_back('1');
                    b.push_back('0');
                }
            }
            mp[a]++,mp[b]++;
            ans=max({mp[a],ans,mp[b]});
        }
        return ans;
    }
};