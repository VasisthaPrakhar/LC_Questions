class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<int>row,col,inr(k,0),inc(k,0);
        map<int,set<int>>adjr,adjc;
        for(auto x:rc){
            adjr[x[0]-1].insert(x[1]-1);
        }
        for(int i=0;i<k;i++){
            for(auto x:adjr[i]){
                inr[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<k;i++){
            if(inr[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            row.push_back(node);
            for(auto x:adjr[node]){
                inr[x]--;
                if(inr[x]==0){
                    q.push(x);
                }   
            }
        }
        
        for(auto x:cc){
            adjc[x[0]-1].insert(x[1]-1);
        }
        for(int i=0;i<k;i++){
            for(auto x:adjc[i]){
                inc[x]++;
            }
        }
        for(int i=0;i<k;i++){
            if(inc[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            col.push_back(node);
            for(auto x:adjc[node]){
                inc[x]--;
                if(inc[x]==0){
                    q.push(x);
                }   
            }
        }
        if(row.size()!=k || col.size()!=k){
            return {};
        }
        map<int,vector<int>>m;
        for(int i=0;i<row.size();i++){
            m[row[i]].push_back(i);
        }
         for(int i=0;i<col.size();i++){
            m[col[i]].push_back(i);
        }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0,j=1;i<k;i++,j++){
            ans[m[i][0]][m[i][1]]=j;
        }
        return ans;
    }
};