class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<int,vector<int>>mr;
        vector<vector<int>>mc(n,vector<int>(m,INT_MIN));
        for(int i=0;i<n;i++){
            vector<int>suf;
            int ma=INT_MIN;
            for(int j=m-1;j>=0;j--){
                ma=max(grid[i][j],ma);
                suf.push_back(ma);
            }
            reverse(suf.begin(),suf.end());
            mr[i]=suf;
        }
        for(int j=0;j<m;j++){
            int ma=INT_MIN;
            for(int i=n-1;i>=0;i--){
                ma=max(mr[i][j],ma);
                mc[i][j]=ma;
            }
        }
        // for(auto x:mc){
        //    // cout<<x.first<<" : ";
        //     for(auto y:x){
        //         cout<<y<<" ; ";
        //     }
        //     cout<<endl;
        // }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=-1,b=-1;
                if(i+1<n){
                    a=mc[i+1][j];
                }
                if(j+1<m){
                    b=mc[i][j+1];
                }
                if(a>-1 || b>-1){
                    //cout<<i<<" "<<j <<" "<<grid[i][j]<<" "<<max(a,b)<<endl;
                    ans=max(ans,max(a,b)-grid[i][j]);
                }
            }
        }
        return ans;
    }
};