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