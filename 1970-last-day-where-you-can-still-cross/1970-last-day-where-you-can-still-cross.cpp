class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    bool bfs(int n,int m,vector<vector<int>>&c, int k){
        queue<pair<int,int>>q;
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<k;i++){
            mat[c[i][0]-1][c[i][1]-1]=1;
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==0){
                q.push({0,i});
                mat[0][i]=1;
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node.first==n-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nr=node.first+dr[i];
                int nc=node.second+dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m || mat[nr][nc]==1){
                    continue;
                }
                q.push({nr,nc});
                mat[nr][nc]=1;
            }
        }
        return false;
    }
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int sz=cells.size();
        int beg=0,end=sz-1,ans;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(bfs(n,m,cells,mid)){
                beg=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};