static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
//     int dr[4] = {1, -1, 0, 0}; 
//     int dc[4] = {0, 0, -1, 1};
//     int bfs(vector<vector<int>>& grid,queue<pair<int,int>> qu){
//         int n=grid.size();
//         int m=grid[0].size();
//         int ans=-1;
//         while (!qu.empty()) { 
//             int s=qu.size();
//             while(s--){
//                 auto current = qu.front();
//                 qu.pop();
//                 for (int i = 0; i < 4; i++) { 
//                     int R = current.first + dr[i]; 
//                     int C = current.second + dc[i];

//                     if (R < 0 or R >= n or C < 0 or C >= m) continue; 
//                     if (grid[R][C] != 1) continue;
                    
//                     grid[R][C] = 2; 
//                     qu.push({R, C});
//                 }
//             }
//             ans++;
//         }
//         return ans;
//     }
//     int orangesRotting(vector<vector<int>>& grid) {
//        int n=grid.size();
//         int m=grid[0].size();
//         int ans=0;
//         queue<pair<int,int>> qu;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2){
//                     qu.push({i,j});
//                 }
//             }
//         }
//         ans=max(bfs(grid,qu),ans);
//         //cout<<ans<<" ";
//          for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     return -1;
//                 }
//             }
//         }
//         return ans;
//     }
    int orangesRotting(vector<vector<int>>& grid) {
        int ct=0, res=-1;
        queue<vector<int>> q;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]>0) ct++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        while(!q.empty()) {
            res++;
            int size=q.size();
            for(int k=0;k<size;k++) {
                vector<int> cur=q.front();
                ct--;
                q.pop();
                for(int i=0;i<4;i++) {
                    int x=cur[0]+dir[i][0], y=cur[1]+dir[i][1];
                    if(x>=grid.size()||x<0||y>=grid[0].size()||y<0||grid[x][y]!=1) continue;
                    grid[x][y]=2;
                    q.push({x, y});
                }
            }
        }
        if(ct==0) return max(0, res);
        return -1;
    }
};