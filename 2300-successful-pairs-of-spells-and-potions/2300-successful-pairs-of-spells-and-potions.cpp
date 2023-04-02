class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long s) {
        int n=sp.size();
        int m=po.size();
        vector<int>ans(n);
        sort(po.begin(),po.end());
        for(int i=0;i<n;i++){
            long long t=ceil((long double)s/(long double)sp[i]);
            auto f=lower_bound(po.begin(),po.end(),t)-po.begin();
            ans[i]=m-f;
        }
        return ans;
    }
};