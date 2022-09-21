class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        vector<int>pre(1000005,0);
        int ma=0;
        for(auto x:in){
            ma=max(ma,x[1]);
            pre[x[0]]+=1;
            pre[x[1]+1]+=-1;
        }
        int ans=pre[0];
        for(int i=1;i<=ma;i++){
            pre[i]+=pre[i-1];
            ans=max(ans,pre[i]);
        }
        return ans;
    }
};