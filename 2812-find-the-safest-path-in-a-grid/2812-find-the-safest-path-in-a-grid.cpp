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
        // queue<pair<int,int>>q;
        // q.push({0,0});
        // int ans=0;
        // while(!q.empty()){
        //     auto node=q.front();
        //     int x=node.first;
        //     int y=node.second;
        //     q.pop();
        //     if(x==n-1 && y==n-1){
        //         ans=max(a[x][y],ans);
        //         continue;
        //     }
        //     for(int i=0;i<4;i++){
        //         int nr=node.first+dr[i];
        //         int nc=node.second+dc[i];
        //         if(nr<0 || nr>=n || nc<0 || nc>=n || a[nr][nc]==0){continue;}
        //         if(vis.find({nr,nc})!=vis.end()){
        //             a[nr][nc]=max(a[nr][nc],a[x][y]);
        //         }else{
        //             a[nr][nc]=min(a[nr][nc],a[x][y]);
        //             vis.insert({nr,nc});
        //         }
        //         q.push({nr,nc});
        //     }
        //     a[x][y]=0;
        // }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({a[0][0], {0,0}});

        while(!pq.empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if(temp.first == n - 1 && temp.second == n - 1) return safe;
            vis.insert({temp.first,temp.second});
            for(int i = 0; i < 4; i++) {
                int x = temp.first + dr[i];
                int y = temp.second + dc[i];

                if(x >= 0 && x < n && y >= 0 && y < n && vis.find({x,y})==vis.end()){
                    int s = min(safe, a[x][y]);
                    pq.push({s, {x, y}});
                    vis.insert({x,y});
                }
            }
        }

        return -1;
    }
};