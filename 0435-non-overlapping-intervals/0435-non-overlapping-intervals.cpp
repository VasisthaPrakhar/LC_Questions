class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n=v.size(),ans=1;
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b)->bool{
            return a[1]<b[1];
        });
        int end=v[0][1];
        for(int i=1;i<n;i++){
            if(end<=v[i][0]){
                end=v[i][1];
                ans++;
            }
        }
        return n-ans;
    }
};