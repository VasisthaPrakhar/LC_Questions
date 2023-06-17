class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int fun(vector<int>& a, vector<int>& b,int n,int idx,int prev){
        if(idx==n){
            return 0;
        }
        if(dp.count(idx)){
            if(dp[idx].count(prev)){
                return dp[idx][prev];
            }
        }
        //cout<<a[idx]<<" "<<prev<<endl;
        auto f=upper_bound(b.begin(),b.end(),prev)-b.begin();
        int res=2002;
        if(f<b.size() && b[f]>prev){
            res=fun(a,b,n,idx+1,b[f])+1;
            //cout<<f;
        }
        if(prev<a[idx]){
            res=min(res,fun(a,b,n,idx+1,a[idx]));
        }
        return dp[idx][prev]=res;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        sort(arr2.begin(),arr2.end());
        dp.clear();
        int ans=fun(arr1,arr2,n,0,-1);
        return ans>=2002?-1:ans;
    }
};