class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<int>res(n,0);
        // for(int i=0;i<n;i++){
        //     auto it=lower_bound(res.begin(),res.end(),nums[i]);
        //     if(it-res.begin()==res.size()){
        //         res.push_back(nums[i]);
        //     }else{
        //         *it=nums[i];
        //     }
        // }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && res[i]<res[j]+1){
                    res[i]=res[j]+1;
                }
            }
        }
        return *max_element(res.begin(),res.end())+1;
    }
};