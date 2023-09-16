// class Solution {
// public:
//     int dr[4]={0,0,1,-1};
//     int dc[4]={1,-1,0,0};
//     int ans;
//     void dfs(int r,int c,set<pair<int,int>>vis,vector<vector<int>>&grid, int n, int m,int k){
//         if(r==n-1 && c==m-1){
//             ans=min(ans,k);
//             return;
//         }
//         vis.insert({r,c});
//         for(int i=0;i<4;i++){
//             int nr=r+dr[i];
//             int nc=c+dc[i];
//             if(nr<0 || nr>=n || nc<0 ||nc>=m || vis.find({nr,nc})!=vis.end()){
//                 continue;
//             }
//             dfs(nr,nc,vis,grid,n,m,max(k,abs(grid[nr][nc]-grid[r][c])));
//         }
//         vis.erase({r,c});
//     }
//     int minimumEffortPath(vector<vector<int>>& h) {
//         int n=h.size();
//         int m=h[0].size();
//         set<pair<int,int>>vis;
//         ans=INT_MAX;
//         dfs(0,0,vis,h,n,m,0);
//         return ans;
//     }
// };
class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    bool bfs(vector<vector<int>>&t,vector<vector<int>>&grid,int mid,int n,int m){
        grid=t;
        queue<pair<int,pair<int,int>>>q;
        q.push({grid[0][0],{0,0}});
        grid[0][0]=-1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.second.first;
            int y=node.second.second;
            if(x==n-1 && y==m-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]==-1){continue;}
                int temp=abs(node.first-grid[nx][ny]);
                if(temp > mid){
                    continue;
                }
                int k=grid[nx][ny];
                grid[nx][ny]=-1;
                q.push({k,{nx,ny}});
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> mat=h;
        int beg=0,end=1e6,ans;
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(bfs(mat,h,mid,n,m)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};