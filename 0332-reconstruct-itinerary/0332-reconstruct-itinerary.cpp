class Solution {
public:
     void dfs(string node,unordered_map<string, multiset<string>> &m,vector<string>&ans){
         
        while(m[node].size()){
            auto temp=m[node].begin();
            string dest=*temp;
            m[node].erase(m[node].begin());
            dfs(dest,m,ans);            
        }
         ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        unordered_map<string, multiset<string>>m;
        vector<string> ans;
        for(int i=0;i<t.size();i++){
            m[t[i][0]].insert(t[i][1]);
        }
        dfs("JFK",m,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};