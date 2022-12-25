class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n=nums.size(),m=q.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(m,0);
        for(int i=0;i<m;i++){
            int sum=0,cnt=0,j=0;
            while(j<n){
                sum+=nums[j++];
                if(sum>q[i]){
                    break;
                }
                cnt++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};