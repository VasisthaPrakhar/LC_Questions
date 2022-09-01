class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int k=nums[i]+nums[j];
                int f=lower_bound(nums.begin()+j+1,nums.end(),k)-nums.begin();
                if(f==n){
                    ans+=f-j-1;
                    continue;
                }
                ans+=f-j-1;
            }
        }
        return ans;
    }
};