class Solution {
public:
    bool check(string &s){
        string t="123450";
        return s==t;
    }
    // void fun(int idx,string s,vector<vector<int>>&v,int k,set<string>&vis){
    //     if(check(s)){
    //         ans=min(ans,k);
    //         return;
    //     }
    //     //cout<<idx<<endl;
    //     vis.insert(s);
    //     for(auto x:v[idx]){
    //         swap(s[idx],s[x]);
    //         if(vis.find(s)==vis.end()){
    //             //vis.insert(s);
    //             fun(x,s,v,k+1,vis);
    //             //vis.erase(s);
    //         }
    //         swap(s[idx],s[x]);
    //     }
    //     vis.erase(s);
    // }
    int slidingPuzzle(vector<vector<int>>& b) {
        string s="";
        int k=0,idx=5;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                s.push_back('0'+b[i][j]);
                if(b[i][j]==0){
                    idx=k;
                }
                k++;
            }
        }
        vector<vector<int>>v={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string>vis;
        int ans=0;
        vis.insert(s);
        queue<pair<int,string>>q;
        q.push({idx,s});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                //cout<<node.second<<" ";
                if(check(node.second)){
                    return ans;
                }
                for(auto x:v[node.first]){
                    swap(node.second[node.first],node.second[x]);
                    if(vis.find(node.second)==vis.end()){
                        vis.insert(node.second);
                        q.push({x,node.second});
                    }
                    swap(node.second[node.first],node.second[x]);
                }
            }
            //cout<<endl;
            ans++;
        }
        return -1;
    }
};