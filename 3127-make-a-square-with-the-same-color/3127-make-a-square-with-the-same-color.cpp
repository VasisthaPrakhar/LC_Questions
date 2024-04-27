class Solution {
public:
    bool check(vector<vector<char>>& grid){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(grid[i][j]==grid[i+1][j] && grid[i][j]==grid[i][j+1] && grid[i][j]==grid[i+1][j+1]){
                    return true;
                }
            }
        }
        return false;
    }
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                char temp = grid[i][j];
                if(grid[i][j]=='W'){
                    grid[i][j]='B';
                }else{
                   grid[i][j]='W'; 
                }
                if(check(grid)){
                    return true;
                }
                grid[i][j]=temp;
            }
        }
        return false;
    }
};