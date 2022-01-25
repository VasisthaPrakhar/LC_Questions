class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int>& a,vector<int>& b,int i){
        if(i>=a.size()){
            ans.push_back(b);
            return;
        }
        fun(ans,a,b,i+1);
        b.push_back(a[i]);
        fun(ans,a,b,i+1);
        b.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<int>b;
        vector<vector<int>>ans;
        fun(ans,a,b,0);
        return ans;
    }
};