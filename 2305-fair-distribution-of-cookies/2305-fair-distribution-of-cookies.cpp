class Solution {
public:
    int fun(int idx, vector<int>&c, vector<int>&child, int k, int n){
        if(idx==n){
            int res=0;
            for(auto x:child){
                res=max(x,res);
            }
            return res;
        }
        int res=INT_MAX;
        for(int i=0;i<k;i++){
            child[i]+=c[idx];
            res=min(res,fun(idx+1,c,child,k,n));
            child[i]-=c[idx];
        }
        return res;
    }
    int distributeCookies(vector<int>& c, int k) {
        int n=c.size();
        vector<int>ch(k,0);
        return fun(0,c,ch,k,n);
    }
};