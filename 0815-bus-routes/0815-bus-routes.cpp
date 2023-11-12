class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        int n=r.size();
        vector<unordered_set<int>>v;
        unordered_map<int,unordered_set<int>>m;
        unordered_set<int>vis,vis1;
        queue<int>q;
        for(int i=0;i<n;i++){
            unordered_set<int>temp;
            for(auto y:r[i]){
                if(y==s){
                    q.push(i);
                    vis.insert(i);
                }
                m[y].insert(i);
                temp.insert(y);
            }
            v.push_back(temp);
        }
        //cout<<q.size()<<" "<<n<<endl;
        if(q.size()==0){return -1;}
        if(s==t && q.size()){return 0;}
        int ans=0;
        while(!q.empty()){
            ans++;
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                //cout<<node<<" ";
                if(v[node].find(t)!=v[node].end()){
                    return ans;
                }
                for(auto x:v[node]){
                    if(vis1.find(x)==vis1.end()){
                        for(auto y:m[x]){
                            if(vis.find(y)==vis.end()){
                                q.push(y);
                                vis.insert(y);
                            }
                        }
                        vis1.insert(x);
                    }
                }
            }
        }
        return -1;
    }
};