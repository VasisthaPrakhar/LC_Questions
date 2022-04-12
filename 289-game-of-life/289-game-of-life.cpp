class Solution {
public:
    int dr[8]={1,-1,0,0,1,-1,1,-1};
    int dc[8]={0,0,1,-1,1,-1,-1,1};
    int fun(vector<vector<int>>& board,int n,int m,int r,int c){
        int ans=0;
        for(int i=0;i<8;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nc<0 || nr>=n || nc>=m){continue;}
            if(board[nr][nc]==1){
                ans++;
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=fun(board,n,m,i,j);
                if(board[i][j]==1){
                    grid[i][j]=1;
                    if(k<2 || k>3){
                        grid[i][j]=0;
                    }
                }else{
                    if(k==3){
                        grid[i][j]=1;
                    }
                }
            }
        }
        board=grid;
    }
};