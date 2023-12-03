class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int px=p[0][0],py=p[0][1],ans=0;
        for(auto x:p){
            ans+=max(abs(x[0]-px),abs(x[1]-py));
            px=x[0],py=x[1];
        }
        return ans;
    }
};