class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int l=in[0][0],r=in[0][1];
        int ans=1;
        for(int i=1;i<in.size();i++){
            if(in[i][0]!=l){
                if(in[i][1]>r){
                    r=max(in[i][1],r);
                    ans++;
                    l=in[i][0];
                }
            }else{
                r=max(in[i][1],r);
            }
        }
        return ans;
    }
};