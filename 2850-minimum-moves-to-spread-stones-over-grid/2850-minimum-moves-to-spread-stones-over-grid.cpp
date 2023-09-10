class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    map<int,map<map<pair<int,int>,int>,int>>dp;
    int fun(vector<pair<int,int>>&a,int idx,int n,map<pair<int,int>,int>&m){
        if(m.size()==0){
            return 0;
        }
        if(idx==n){
            return INT_MAX;
        }
        if(dp[idx][m]){
            return dp[idx][m];
        }
        int r=a[idx].first;
        int c=a[idx].second;
        queue<pair<int,int>>q;
        q.push({r,c});
        set<pair<int,int>>s;
        s.insert({r,c});
        int cnt=0;
        long long int res=INT_MAX;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(m.count(node)){
                    m[node]--;
                    if(m[node]==0){
                        m.erase(node);
                    }
                    res=min(res,(long long)cnt+fun(a,idx+1,n,m));
                    m[node]++;
                }
                for(int i=0;i<4;i++){
                    int nr=dr[i]+node.first;
                    int nc=dc[i]+node.second;
                    if(nr<0 || nr>=3 || nc<0 || nc>=3 || s.find({nr,nc})!=s.end()){
                        continue;
                    }
                    q.push({nr,nc});
                    s.insert({nr,nc});
                }
            }
            cnt++;
        }
        return dp[idx][m]=res>=INT_MAX?INT_MAX:res;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        map<pair<int,int>,int>m;
        vector<pair<int,int>>a;
         for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]>1){
                    m[{i,j}]=grid[i][j]-1;
                }
                if(grid[i][j]==0){
                    a.push_back({i,j});
                }
            }
        }
        return fun(a,0,a.size(),m);
    }
};