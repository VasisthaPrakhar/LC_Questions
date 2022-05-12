class Solution {
public:
    set<vector<int>>s;
    void fun(vector<int>& a,int n,int idx,int vis[],vector<int>&res){
        if(idx>=n){
            s.insert(res);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                res.push_back(a[i]);
                fun(a,n,idx+1,vis,res);
                vis[i]=0;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int vis[9]={0};
        fun(nums,n,0,vis,res);
        vector<vector<int>>ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};