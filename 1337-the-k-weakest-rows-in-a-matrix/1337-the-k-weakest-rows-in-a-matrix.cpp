class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        set<pair<int,int>>s;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=mat[i][j];
            }
            s.insert({sum,i});
        }
        auto it=s.begin();
        while(k-- && it!=s.end()){
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};