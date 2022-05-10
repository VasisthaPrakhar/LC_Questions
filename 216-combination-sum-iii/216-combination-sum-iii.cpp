class Solution {
public:
    vector<vector<int>>ans;
    void fun(int id,int idx,int k,int n,vector<int>&res){
        if(idx==k && n==0){
            ans.push_back(res);
            return;
        }else if(idx==k){
            return;
        }else{
            for(int i=id;i<=9;i++){
                if(n>=i){
                    res.push_back(i);
                    fun(i+1,idx+1,k,n-i,res);
                    res.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n){
            return ans;
        }
        vector<int>res;
        fun(1,0,k,n,res);
        return ans;
    }
};