class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int>m;
        set<int>win;
        int n=mat.size();
        for(int i=0;i<n;i++){
            m[mat[i][1]]++;
            if(win.find(mat[i][1])!=win.end()){
                win.erase(mat[i][1]);
            }
            if(!m.count(mat[i][0]))
                win.insert(mat[i][0]);
        }
        vector<int>a,b(win.begin(),win.end());
        for(auto x:m){
            if(x.second==1){
                a.push_back(x.first);
            }
        }
        return {b,a};
    }
};