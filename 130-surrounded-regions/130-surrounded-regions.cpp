static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
   int dr[4] = {1, -1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 
    int m,n;
    void bfs(vector<vector<char>>& board, queue<pair<int,int>>&qu) {
        while (!qu.empty()) { 
            auto current = qu.front();
            qu.pop();

            for (int i = 0; i < 4; i++) { 
                int R = current.first + dr[i]; 
                int C = current.second + dc[i];

                if (R < 0 or R >= n or C < 0 or C >= m) continue; 
                if (board[R][C] != 'O') continue;
                board[R][C] = 'D';

                qu.push({R, C});
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        queue<pair<int,int>>qu;
        if(n<=2 || m<=2){
            return;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if (i == 0 || j == 0 || i == n - 1 || j == m - 1){
                     if(board[i][j]=='O'){
                         board[i][j]='D';
                          qu.push({i,j});
                     }
                }
            }
        }
        bfs(board,qu);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){board[i][j]='X';}
                else if(board[i][j]=='D'){board[i][j]='O';}
            }
        }
        return;
    }
};