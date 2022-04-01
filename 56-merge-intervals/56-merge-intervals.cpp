class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();
        if(n==1){
            return in;
        }
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        int beg=in[0][0],end=in[0][1];
        for(int i=1;i<n;i++){
            if(in[i][0]<=end){
                end=max(end,in[i][1]);
            }else{
                ans.push_back({beg,end});
                beg=in[i][0];
                end=in[i][1];
            }
        }
        ans.push_back({beg,end});
        return ans;
    }
};