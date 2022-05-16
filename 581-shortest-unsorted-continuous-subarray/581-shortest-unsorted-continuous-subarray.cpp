class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>a=nums;
        sort(nums.begin(),nums.end());
        int l=-1,r=-1;
        for(int i=0;i<a.size();i++){
            if(nums[i]!=a[i]){
                if(l==-1){
                    l=i;
                }
                r=i;
            }
        }
        if(l==-1){
            return 0;
        }
        return r-l+1;
    }
};