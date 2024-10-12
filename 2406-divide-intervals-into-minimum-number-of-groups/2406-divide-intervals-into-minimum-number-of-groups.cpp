class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        //vector<int>pre(1000005,0);
        map<int,int>pre;
        int ma=0;
        for(auto x:in){
            ma=max(ma,x[1]);
            pre[x[0]]+=1;
            pre[x[1]+1]-=1;
        }
        int ans=0,k=0;
        for(auto x:pre){
            k+=x.second;
            ans=max(ans,k);
        }
        return ans;
    }
};