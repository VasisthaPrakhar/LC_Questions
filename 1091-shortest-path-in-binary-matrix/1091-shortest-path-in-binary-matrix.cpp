class Solution {
public:
    int dr[8]={0,0,1,-1,1,1,-1,-1};
    int dc[8]={1,-1,0,0,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int ans=0,n=grid.size();
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=2;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node.first==n-1 && node.second==n-1){
                    return ans+1;
                }
                for(int i=0;i<8;i++){
                    int nx=node.first+dr[i];
                    int ny=node.second+dc[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=n || grid[nx][ny]!=0){
                        continue;
                    }
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            ans++;
        }
        return -1;
    }
};