class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[1][0]>1 && grid[0][1]>1){return -1;}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,0,0});
        map<pair<int,int>,int>mp;
        mp[{0,0}]=0;
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=node[1] + dr[i];
                int nc=node[2] +dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m){continue;}
                if(mp.find({nr,nc})!=mp.end()){
                    if(mp[{node[1],node[2]}]+1>=grid[nr][nc])
                        mp[{nr,nc}]=min(mp[{node[1],node[2]}]+1,mp[{nr,nc}]);
                    continue;
                }
                int z=0,c=mp[{node[1],node[2]}];
                if(c < grid[nr][nc]){
                    if((c-grid[nr][nc])%2==0){
                        //cout<<nr<<" "<<nc<<endl;
                        z++;
                    }
                }
                mp[{nr,nc}]=max(c+1,grid[nr][nc]+z);
                q.push({ mp[{nr,nc}],nr,nc});
            }
        }
        // for(auto x:mp){
        //     cout<<"{"<<x.first.first<<", "<<x.first.second<<"}"<<" == "<<x.second<<endl;
        // }
        // cout<<endl;
        return mp[{n-1,m-1}];
    }
};