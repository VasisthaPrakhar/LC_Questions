class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size(),a=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            a^=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            int k=0;;
            for(int j=0;j<maximumBit;j++){
                if(!(a & (1<<j))){
                    k=k|(1<<j);
                }
            }
            ans.push_back(k);
            a^=nums[i];
        }
        return ans;
    }
};