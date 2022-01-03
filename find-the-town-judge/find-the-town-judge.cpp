class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        unordered_map<int,vector<int>>adj,adj1;
        int m=t.size();
        if(m==0 && n==1){
            return 1;
        }
        for(int i=0;i<m;i++){
            adj[t[i][1]].push_back(t[i][0]);
            adj1[t[i][0]].push_back(t[i][1]);
        }
        int flag=-1;
        for(int i=1;i<=n;i++){
            if(adj.count(i) && adj[i].size()==n-1){
                if(adj1.count(i)==0){
                    flag=i;
                    break;
                }
            }
        }
        return flag;
    }
};