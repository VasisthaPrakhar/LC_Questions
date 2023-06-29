// class Solution {
// public:
//     bool cl(char ch){
//         return ((ch-'A')>=0)&&((ch-'A')<=25);
//     }
//     bool ck(char ch){
//         return ((ch-'a')>=0)&&((ch-'a')<=25);
//     }
//     int dr[4]={1,-1,0,0};
//     int dc[4]={0,0,1,-1};
//     int fun(vector<string>& grid,int n,int m,int r,int c,int &k,set<pair<int,int>>&vis,set<char>&key){
//         if(r<0 || r>=n || c<0 || c>=m || vis.find({r,c})!=vis.end() || grid[r][c]=='#'){
//             return 0;
//         }
//         if(cl(grid[r][c]) && key.find(tolower(grid[r][c]))==key.end()){return 0;}
//         vis.insert({r,c});
//         int res=0;
//         if(ck(grid[r][c])){
//             res++;
//             k--;
//         }
//         for(int i=0;i<4;i++){
//             int nr=r+dr[i];
//             int nc=c+dc[i];
//             res+=fun(grid,n,m,nr,nc,k,vis,key)+1;    
//         }
//     }
//     int fun(vector<string>& grid,int n,int m,int r,int c,int k){
//         queue<pair<int,int>>q;
//         q.push({r,c});
//         set<pair<int,int>>vis;
//         unordered_set<char>key;
//         vis.insert({r,c});
//         int ans=0;
//         while(!q.empty()){
//             int sz=q.size();
//             while(sz--){
//                 auto node=q.front();
//                 q.pop();
//                 if(ck(grid[node.first][node.second])){
//                     k--;
//                     key.insert(grid[node.first][node.second]);
//                     if(k==0){
//                         break;
//                     }
//                 }
//                 //cout<<node.first<<" "<<node.second<<endl;
//                 for(int i=0;i<4;i++){
//                     int nr=node.first+dr[i];
//                     int nc=node.second+dc[i];
//                     if(nr<0 || nr>=n || nc<0 || nc>=m || vis.find({nr,nc})!=vis.end() || grid[nr][nc]=='#'){
//                         continue;
//                     }
//                     if(cl(grid[nr][nc]) && key.find(tolower(grid[nr][nc]))==key.end()){continue;}
//                     q.push({nr,nc});
//                     vis.insert({nr,nc});
//                 }
//             }
//             if(k==0){
//                 break;
//             }
//             ans++;
//         }
//         //cout<<k;
//         if(k==0){
//             return ans;
//         }else{
//             return -1;
//         }
//     }
//     int shortestPathAllKeys(vector<string>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int ans=0,r=0,c=0,k=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]=='@'){
//                     r=i,c=j; 
//                 }
//                 if(cl(grid[i][j])){
//                     k++;
//                 }
//             }
//         }
//         //cout<<k;
//         ans=fun(grid,n,m,r,c,k);
//         return ans;
//     }
// };
class Solution {
    public:
int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(), n=m?grid[0].size():0;
    if(!m || !n) return 0;
    int path=0, K=0;
    vector<int> dirs={0,-1,0,1,0};
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0))); //at most 6 keys, using bitmap 111111
    queue<pair<int,int>> q; //<postion, hold keys mapping>
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                q.push({i*n+j,0});
                visited[i][j][0]=1;                    
            }
            if(grid[i][j]>='A' && grid[i][j]<='F') K++; //total alpha number
        }
    }
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int a=q.front().first/n, b=q.front().first%n;
            int carry=q.front().second;
            q.pop();        
            if(carry==((1<<K)-1)) return path; //if all keys hold, just return 
            for(int j=0;j<4;j++){
                int x=a+dirs[j], y=b+dirs[j+1], k=carry;
                if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='#') continue;
                if(grid[x][y]>='a' && grid[x][y]<='f'){
                    k=carry|(1<<(grid[x][y]-'a')); //update hold keys
                }
                else if(grid[x][y]>='A' && grid[x][y]<='F'){
                    if(!(carry & (1<<(grid[x][y]-'A')))) continue;
                }
                if(!visited[x][y][k]){
                    visited[x][y][k]=1;
                    q.push({x*n+y,k});
               }                
            }
        }
        path++;
    }
    return -1;
}
};