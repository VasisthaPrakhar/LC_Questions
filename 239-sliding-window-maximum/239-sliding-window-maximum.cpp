class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>q;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        int j=k;
        while(j<n){
            if(!q.empty() && q.front()==j-k){
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()]<nums[j]){
                q.pop_back();
            }
            q.push_back(j);
            ans.push_back(nums[q.front()]);
            j++;
        }
        return ans;
    }
};