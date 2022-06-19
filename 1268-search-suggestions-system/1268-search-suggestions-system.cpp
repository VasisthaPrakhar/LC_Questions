class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        unordered_map<string,set<string>>m;
        int n=p.size();
        for(int i=0;i<n;i++){
            int m1=p[i].length();
            string t="";
            for(int j=0;j<m1;j++){
                t+=p[i][j];
                m[t].insert(p[i]);
            }
        }
        int k=s.length();
        vector<vector<string>>ans;
        string t="";
        for(int i=0;i<k;i++){
            t+=s[i];
            vector<string>v;
            int z=3;
            while(!m[t].empty() && z){
                v.push_back(*m[t].begin());
                m[t].erase(v.back());
                z--;
            }
            ans.push_back(v);
        }
        return ans;
    }
};