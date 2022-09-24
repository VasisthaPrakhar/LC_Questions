class Solution {
public:
    int ans=0;
    void fun(vector<vector<int>>& grid, int num, int col, int n, int m){ 
        if(num<=0){
            //cout<<"debug "<<col<<endl;
            int cnt=0;
            for(int i=0;i<n;i++){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    cnt++;
                }
            }
            ans=max(ans,cnt);
            //cout<<ans<<endl;
            return;
        }
        if(col>=m){
            return;
        }
        vector<int>r;
        for(int i=0;i<n;i++){
            if(grid[i][col]==1){
                r.push_back(i);
                grid[i][col]=3;
            }
        }
        fun(grid,num-1,col+1,n,m);
        for(auto x:r){
            grid[x][col]=1;
        }
        fun(grid,num,col+1,n,m);
    }
    int maximumRows(vector<vector<int>>& grid, int num) {
        int n=grid.size();
        int m=grid[0].size();
        fun(grid,num,0,n,m);
        return ans;
    }
};