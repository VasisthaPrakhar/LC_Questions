class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapp, vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            string temp=to_string(nums[i]);
            int num=0;
            for(auto x:temp){
                num=num*10 + mapp[x-'0'];
            }
            pq.push({num,i});
        }
        vector<int>ans(n);
        int j=n-1;
        while(!pq.empty()){
            ans[j]=nums[pq.top().second];
            j--;
            pq.pop();
        }
        return ans;
    }
};