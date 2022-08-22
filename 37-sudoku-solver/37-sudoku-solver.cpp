class Solution {
public:
    vector<vector<char>>ans;
    bool checkrow(vector<vector<char>>& grid,int m,int r,char ch){
        for(int i=0;i<m;i++){
            if(ch==grid[r][i]){
                return false;
            }
        }
        return true;
    }
    bool checkcol(vector<vector<char>>& grid,int n,int c,char ch){
        for(int i=0;i<n;i++){
            if(ch==grid[i][c]){
                return false;
            }
        }
        return true;
    }
    bool checkbox(vector<vector<char>>& grid,int n,int m,int r,int c,char ch){
        // vector<int>a={0,3,6,9};
        // int f=lower_bound(a.begin(),a.end(),r)-a.begin();
        // int ir,ic,fr,fc;
        // if(r==a[f]){
        //     ir=a[f];
        //     fr=a[f+1];
        // }else{
        //     ir=a[f-1];
        //     fr=a[f];
        // }
        // f=lower_bound(a.begin(),a.end(),c)-a.begin();
        // if(c==a[f]){
        //     ic=a[f];
        //     fc=a[f+1];
        // }else{
        //     ic=a[f-1];
        //     fc=a[f];
        // }
        // for(int i=ir;i<fr;i++){
        //     for(int j=ic;j<fc;j++){
        //         if(grid[i][j]==ch){
        //             return false;
        //         }
        //     }
        // }
        int ir=(r/3)*3;
        int fr=((r/3)+1)*3;
        int ic=(c/3)*3;
        int fc=((c/3)+1)*3;
        for(int i=ir;i<fr;i++){
            for(int j=ic;j<fc;j++){
                if(grid[i][j]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    void fun(vector<vector<char>>& grid,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(checkrow(grid,m,i,ch) && checkcol(grid,n,j,ch) && checkbox(grid,n,m,i,j,ch)){
                            grid[i][j]=ch;
                            fun(grid,n,m);
                            if(ans.size()==0)
                                grid[i][j]='.';
                        }
                    }
                    return;
                }               
            }
        }
        if(ans.size()==0){
            ans=grid;
        }
    }
    void solveSudoku(vector<vector<char>>& grid) {
        int n=9,m=9;
        fun(grid,n,m);
        grid=ans;
    }
};