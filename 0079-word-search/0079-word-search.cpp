class Solution {
public:
    int n,m,p;
    string s;
    int dr[4] = {1, -1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 
    bool dfs(int r, int c, vector<vector<char>>& grid, int q) { 
    if(q>=p){
        return true;
    }
    if (r < 0 or r >= n or c < 0 or c >= m) return false;
       
    if (grid[r][c] != s[q]) return false; 
    char temp=grid[r][c];
    grid[r][c] = '0';
    for (int i = 0; i < 4; i++) { 
        if(dfs(r + dr[i], c + dc[i],grid,q+1))
            return true;
    }
    grid[r][c]=temp;
    return false;
}
    bool exist(vector<vector<char>>& grid, string &word) {
        n=grid.size();
        m=grid[0].size();
        reverse(word.begin(),word.end());
        s=word;
        //cout<<s<<" ";
        p=word.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]){
                    if(dfs(i,j,grid,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};