class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        unordered_map<int,int>c,b;
        int n=q.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(b.find(q[i][0])!=b.end()){
                c[b[q[i][0]]]--;
                if(c[b[q[i][0]]]==0){
                    c.erase(b[q[i][0]]);
                }
            }
            b[q[i][0]]=q[i][1];
            c[q[i][1]]++;
            ans.push_back((int)c.size());
        }
        return ans;
    }
};