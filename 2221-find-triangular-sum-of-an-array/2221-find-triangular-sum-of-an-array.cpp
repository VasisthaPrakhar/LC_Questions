class Solution {
public:
    void fun(vector<int>&t){
        while(t.size()!=1){
            vector<int> t1;
            for(int i = 1; i < t.size(); i++){
                t1.push_back((t[i] + t[i-1]) % 10);
            }            
            t = t1;
        }
    }
    int solve(vector<int>& nums) {
        for(int i=0;i<100;i++){}
        vector<int> t = nums;
        fun(t);
        return t.front();
    }
    int triangularSum(vector<int>& nums) {
        return solve(nums);
    }
};