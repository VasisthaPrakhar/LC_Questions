class Solution {
public:
    void fun(set<vector<int>>&ans,vector<int>& a,vector<int>& b,int i){
        if(i>=a.size()){
            ans.insert(b);
            return;
        }
        fun(ans,a,b,i+1);
        b.push_back(a[i]);
        fun(ans,a,b,i+1);
        b.pop_back();
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<int>b;
        sort(a.begin(), a.end());
        vector<vector<int>>ans;
        set<vector<int>>res;
        fun(res,a,b,0);
        for(auto x:res){
            ans.push_back(x);
        }
        return ans;
    }
};