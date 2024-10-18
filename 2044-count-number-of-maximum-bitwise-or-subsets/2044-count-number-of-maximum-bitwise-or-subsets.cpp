class Solution {
public:
    map<int,int,greater<int>>m;
    void fun(int idx,vector<int>& nums,int n,int res){
        if(idx>=n){
            //cout<<res<<endl;
            m[res]++;
            return;
        }
        fun(idx+1,nums,n,res);
        fun(idx+1,nums,n,res|nums[idx]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        m.clear();
        fun(0,nums,n,0);
        return m.begin()->second;
    }
};