class Solution {
public:
    int dp[51];
    int fun(string &s,int beg, int sz, set<string>&st){
        if(sz-beg<=0){
            return 0;
        }
        if(dp[beg]!=-1){
            return dp[beg];
        }
        int n=sz-beg,res=INT_MAX-5;
        for(int i=n;i>0;i--){
            string t=s.substr(beg,i);
            if(st.find(t)!=st.end()){
                res=min(res,fun(s,beg+i,sz,st));
            }
        }
        if(beg<sz){
            res=min(res,1+fun(s,beg+1,sz,st));
        }
        return dp[beg]=res;
    }
    int minExtraChar(string s, vector<string>& d) {
        int n=s.length();
        set<string>st;
        for(auto x:d){
            st.insert(x);
        }
        memset(dp,-1,sizeof(dp));
        int ans=fun(s,0,n,st);
        return ans;
    }
};