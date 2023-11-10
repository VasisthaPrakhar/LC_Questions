class Solution {
public:
    void fun(map<int,vector<int>>&m, set<int>&vis, int node, vector<int>&ans){
        vis.insert(node);
        ans.push_back(node);
        for(auto x:m[node]){
            if(vis.find(x)==vis.end()){
                fun(m,vis,x,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& a) {
        int n=a.size();
        vector<int>ans;
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[a[i][0]].push_back(a[i][1]);
            m[a[i][1]].push_back(a[i][0]);
        }
        int st=-1;
        for(auto x:m){
            if(x.second.size()==1){
                if(st==-1){
                    st=x.first;
                    break;
                }
            }
        }
        set<int>vis;
        fun(m,vis,st,ans);
        return ans; 
    }
};