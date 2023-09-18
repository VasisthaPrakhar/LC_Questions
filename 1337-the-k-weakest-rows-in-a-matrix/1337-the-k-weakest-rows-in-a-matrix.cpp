class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        set<pair<int,int>>s;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    c++;
                }
            }
            s.insert({c,i});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(s.begin()->second);
            s.erase(s.begin());
        }
        return ans;
    }
};