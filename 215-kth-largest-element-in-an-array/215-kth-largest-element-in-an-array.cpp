class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int>p;
        for(auto x:nums){
            p.push(x);
        }
        while(k>1){
            p.pop();
            k--;
        }
        return p.top();
    }
};