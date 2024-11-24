class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int>ans(n+1,0);
        for(auto x:b){
            ans[x[0]-1]+=x[2];
            ans[x[1]]-=x[2];
        }
        for(int i=1;i<=n;i++){
            ans[i]+=ans[i-1];
        }
        ans.pop_back();
        return ans;
    }
};