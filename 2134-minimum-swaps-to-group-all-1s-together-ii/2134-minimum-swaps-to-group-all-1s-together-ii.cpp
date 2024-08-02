class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c++;
            }
        }
        int k=c-1,z=0,ans=INT_MAX;
        for(int i=0;i<k;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<c;i++){
            if(nums[i]==0){
                z++;
            }
        }
        ans=min(ans,z);
        int j=c,i=0;
        while(j<n+k){
            if(nums[j]==0){
                z++;
            }
            if(nums[i]==0){
                z--;
            }
            ans=min(ans,z);
            j++,i++;
        }
        return ans;
    }
};