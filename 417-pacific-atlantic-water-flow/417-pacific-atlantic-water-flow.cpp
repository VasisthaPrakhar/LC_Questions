class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    set<pair<int,int>>vis;
    bool fun(int r,int c,vector<vector<int>>& h,int n,int m){
        queue<pair<int,int>>q;
        q.push({r,c});
        set<pair<int,int>>s;
        s.insert({r,c});
        bool a=false,b=false;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            if(vis.find({x,y})!=vis.end()){
                return true;
            }
            if(x==n-1 || y==m-1){
                a=true;
            }
            if(x==0 || y==0){
                b=true;
            }
            if(a && b){
                return true;
            }
            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m || s.find({nr,nc})!=s.end() || h[nr][nc]>h[x][y]){
                    continue;
                }
                s.insert({nr,nc});
                q.push({nr,nc});
            }
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 && j==0)||(i==0 && j==m-1)){
                    ans.push_back({i,j});
                    vis.insert({i,j});
                    continue;
                }
                if(fun(i,j,h,n,m)){
                    ans.push_back({i,j});
                    vis.insert({i,j});
                }
            }
        }
        return ans;
    }
};