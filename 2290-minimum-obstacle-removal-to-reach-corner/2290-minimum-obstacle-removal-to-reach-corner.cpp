class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        grid[0][0]=-1;
        int ans=INT_MAX;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int r=node[1],c=node[2],k=node[0];
            //cout<<k<<" "<<r<<" "<<c<<endl;
            if(r==n-1 && c==m-1){
                ans=min(ans,k);
                //cout<<k<<endl;
                continue;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]==-1){
                    continue;
                }
                if(grid[nr][nc]==1){
                    pq.push({k+1,nr,nc});
                }else{
                    pq.push({k,nr,nc});
                }
                grid[nr][nc]=-1;
            }
        }
        return ans;
    }
};