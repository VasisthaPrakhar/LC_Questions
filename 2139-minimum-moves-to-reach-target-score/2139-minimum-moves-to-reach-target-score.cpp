class Solution {
public:
    void fun(int tar, int m,int ans,int &res){
        if(tar==1){
            res=min(ans,res);
            return;
        }
        if(m==0){
            ans+=tar-1;
            res=min(ans,res);
            return;
        }
        if(m && tar%2==0){
            fun(tar/2,m-1,ans+1,res);
        }
        else
        fun(tar-1,m,ans+1,res);       
    }
    int minMoves(int tar, int m) {
        if(m==0){
            return tar-1;
        }
        int ans=INT_MAX;
        fun(tar,m,0,ans);
        return ans;
    }
};