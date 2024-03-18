class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n=p.size();
        sort(p.begin(),p.end());
        int end=p[0][1],ans=1;
        for(int i=1;i<n;i++){
            if(p[i][0]>end){
                end=p[i][1];
                ans++;
            }else{
                end=min(p[i][1],end);
            }
        }
        return ans;
    }
};