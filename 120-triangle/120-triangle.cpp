class Solution {
public:
    // int fun(vector<vector<int>>& t,int n,int idx){
    //     if(n<=0){
    //         return 0;
    //     }
    //     if(n==1){
    //         return t[0][0];
    //     }
    //     int m=t[n-2].size();
    //     if(idx>0){
    //         if(idx<m){
    //             return t[n-1][idx]+min(fun(t,n-1,idx),fun(t,n-1,idx-1));
    //         }else{
    //             return t[n-1][idx]+fun(t,n-1,idx-1);
    //         }
    //     }else{
    //         return t[n-1][idx]+fun(t,n-1,idx);
    //     }
    // }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                t[i][j]+=min(t[i+1][j],t[i+1][j+1]);
            }
        }
        return t[0][0];
    }
};