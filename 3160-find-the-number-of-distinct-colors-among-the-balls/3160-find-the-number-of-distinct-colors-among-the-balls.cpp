class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        map<int,int>c,b;
        int n=q.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            vector<int>x=q[i];
            if(b.find(x[0])!=b.end()){
                c[b[x[0]]]--;
                if(c[b[x[0]]]==0){
                    c.erase(b[x[0]]);
                }
            }
            b[x[0]]=x[1];
            c[x[1]]++;
            ans[i]=c.size();
        }
        return ans;
    }
};