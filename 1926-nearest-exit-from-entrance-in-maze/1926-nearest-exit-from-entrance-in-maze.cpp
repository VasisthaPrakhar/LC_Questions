class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int bfs(vector<vector<char>>& maze,int &n,int &m,int &r,int &c){
        queue<pair<int,int>>q;
        q.push({r,c});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto node=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int R=node.first+dr[i];
                    int C=node.second+dc[i];
                    if(R<0 || R>=n || C<0 || C>=m){
                        if(node.first!=r || node.second!=c){
                            return ans;
                        }
                        else{
                            continue;
                        }
                    }
                    if(maze[R][C]!='.'){
                        continue;
                    }
                    maze[R][C]='!';
                    q.push({R,C});
                }
            }
            ans++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n=maze.size();
        int m=maze[0].size();
        return bfs(maze,n,m,e[0],e[1]);
    }
};