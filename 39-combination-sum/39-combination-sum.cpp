class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>& c, int t,vector<int>&a,int i){
        if(t==0){
            ans.push_back(a);
            return;
        }
        for(;i<c.size();i++){
            if(c[i]<=t){
                a.push_back(c[i]);
                fun(c,t-c[i],a,i);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        //sort(c.begin(),c.end());
        vector<int>a;
        fun(c,t,a,0);
        return ans;
    }
};