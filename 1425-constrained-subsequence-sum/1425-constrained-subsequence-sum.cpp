class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> vec = nums;

        priority_queue<pair<int, int>> pq;

        //initialize max-heap
        pq.push({vec[0], 0});
        int ans = vec[0];

        for(int i = 1; i < n; i++){
            //moving current window
            while(!pq.empty() && (i - pq.top().second > k)){
                pq.pop();
            }

            //processing current window
            vec[i] = max(vec[i], vec[i] + pq.top().first);
            pq.push({vec[i], i});

            ans = max(ans, vec[i]);

        }

        return ans;
    }
};