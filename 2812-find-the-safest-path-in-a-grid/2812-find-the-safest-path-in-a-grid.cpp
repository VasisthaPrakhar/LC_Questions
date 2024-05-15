class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    void bfs(queue<pair<int,int>>&q,int n,vector<vector<int>>& a){
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                auto node=q.front();
                int x=node.first;
                int y=node.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=x+dr[i];
                    int nc=y+dc[i];
                    if(nr<0 || nr>=n || nc<0 || nc>=n || a[nr][nc]<=ans){continue;}
                    q.push({nr,nc});
                    a[nr][nc]=min(ans,a[nr][nc]);
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>>vis;
        queue<pair<int,int>>q;
        vector<vector<int>>a(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    a[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        bfs(q,n,a);
        vis.clear();
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({a[0][0], {0,0}});

        while(!pq.empty()){
            auto node = pq.top().second;
            auto val = pq.top().first;
            int x=node.first;
            int y=node.second;
            pq.pop();

            if(x==n-1 && y==n-1) return val;
            vis.insert({x,y});
            for(int i = 0; i < 4; i++) {
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || vis.find({nr,nc})!=vis.end()){continue;}
                int k = min(val, a[nr][nc]);
                pq.push({k, {nr, nc}});
                vis.insert({nr,nc});
            }
        }

        return -1;
    }
};