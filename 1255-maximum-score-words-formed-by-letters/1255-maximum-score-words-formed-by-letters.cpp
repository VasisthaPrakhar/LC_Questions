class Solution {
private:
    unordered_map<int,map<vector<int>,int>>dp;
public:
    bool check(string &s,vector<int>a){
        for(auto x:s){
            if(a[x-'a']<=0){
                return false;
            }else{
                a[x-'a']--;
            }
        }
        return true;
    }
    int fun(int idx,int n,vector<int>&a,vector<string>&w,vector<int>& s){
        if(idx>=n){
            return 0;
        }
        if(dp.find(idx)!=dp.end()){
            if(dp[idx].find(a)!=dp[idx].end()){
                return dp[idx][a];
            }
        }
        int res=0,res1=0;
        if(check(w[idx],a)){
            int ans=0;
            for(auto &x:w[idx]){
                a[x-'a']--;
                ans+=s[x-'a'];
            }
            res+=ans+fun(idx+1,n,a,w,s);
            for(auto &x:w[idx]){
                a[x-'a']++;
            }
        }
        res1+=fun(idx+1,n,a,w,s);
        return dp[idx][a]=max(res,res1);
    }
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        int n=w.size();
        vector<int>a(26,0);
        for(auto x:l){
            a[x-'a']++;
        }
        dp.clear();
        return fun(0,n,a,w,s);
    }
};