class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size(),sum=0;
        vector<int>a(n,0);
        for(int i=1;i<n;i++){
            if((nums[i]%2 && nums[i-1]%2)||(nums[i]%2==0 && nums[i-1]%2==0)){
                sum+=1;
            }
            a[i]=sum;
        }
        vector<bool>ans;
        for(auto x:q){
            int k=a[x[1]]-a[x[0]];
            ans.push_back(k==0);
        }
        return ans;
    }
};