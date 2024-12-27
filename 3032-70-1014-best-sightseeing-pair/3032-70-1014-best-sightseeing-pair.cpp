class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size(),ma=1,ans=INT_MIN;
        for(int i=0;i<n;i++){
            ma--;
            ans=max(ans,ma+v[i]);
            ma=max(v[i],ma);
        }
        return ans;
    }
};