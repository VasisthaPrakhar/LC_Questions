class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int sum=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                sum+=nums[i];
            }
        }
        for(auto &x:q){
            int k=nums[x[1]]+x[0],j=x[1];
            if(k%2){
                if(nums[j]%2==0){
                    sum-=nums[j];
                }
            }else{
                if(nums[j]%2==0){
                    sum+=x[0];
                }else{
                    sum+=k;
                }
            }
            nums[x[1]]=k;
            ans.push_back(sum);
        }
        return ans;
    }
};