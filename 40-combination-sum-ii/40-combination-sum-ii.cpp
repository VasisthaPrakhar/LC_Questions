class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>& c, int t,vector<int>&a,int i){
        if(t==0){
            ans.push_back(a);
            return;
        }
        int st=i;
        for(;i<c.size();i++){
            if(i>st && c[i]==c[i-1]){continue;}
            if(c[i]<=t){
                a.push_back(c[i]);
                fun(c,t-c[i],a,i+1);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& ca, int target) {
        sort(ca.begin(),ca.end());
        vector<int>a;
        fun(ca,target,a,0);
        //vector<vector<int>>res(ans.begin(),ans.end());
        return ans;   
    }
};