class Solution {
    
    class Tuple {
        public:
            int node;
            int path;
            int cost;
            
            Tuple(int node,int path,int cost){
                this->node = node;
                this->path = path;
                this->cost = cost;
            }
    };   
    
public:
    bool seen[1<<12][12];
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        queue<Tuple>q;
        // unordered_set<pair<int,int>>visited;
        for(int i=0;i<n;i++){
            int temp = 1<<i;
            Tuple t(i,temp,1);
            q.push(t);
            // visited.insert({i,temp});
            seen[1<<i][i] = true;
        }
        
        while(!q.empty()){
            Tuple cur = q.front(); q.pop();
            int curPath = cur.path; int curNode = cur.node;
            if(curPath == (1<<n)-1){
                return cur.cost-1;
            }
            for(auto x: g[curNode]){
                int nextpath = curPath|(1<<x);
                Tuple t(x,nextpath,cur.cost+1);
                if(!seen[nextpath][x]){
                    q.push(t);
                    // visited.insert({x,nextpath});
                    seen[nextpath][x] = true;
                }
            }
        }
        return -1;
    }
};