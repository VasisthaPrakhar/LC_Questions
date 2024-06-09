class Solution {
public:
    map<int,int>dp;
    int fun(vector<int>&a,int n,int prev){
        if(dp.find(prev)!=dp.end()){
            return dp[prev];
        }
        auto f=lower_bound(a.begin(),a.end(),prev)-a.begin();
        f--;
        int res=0;
        for(int i=f;i>=0;i--){
            res=max(res,a[i]+fun(a,n,min(prev-a[i],a[i])));
        }
        return dp[prev]=res;
    }
    
    int maxTotalReward(vector<int>& r) {
        int n=r.size();
        set<int>s;
        for(auto x:r){
            s.insert(x);
        }
        vector<int>a;
        for(auto x:s){
            a.push_back(x);
        }
        int m=a.size();
        dp.clear();
        return a[m-1]+fun(a,m,a[m-1]);
    }
};