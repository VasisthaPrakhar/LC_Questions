class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int m=n-k;
        stack<int>p;
        for(int i=0;i<n;i++){
            while(!p.empty() && p.top()>nums[i] && m){
                p.pop();
                m--;
            }
            p.push(nums[i]);
        }
        vector<int>ans(k);
        while(p.size()>k){
            p.pop();
        }
        k--;
        while(!p.empty()){
            ans[k--]=p.top();
            p.pop();
        }
        return ans;
    }
};