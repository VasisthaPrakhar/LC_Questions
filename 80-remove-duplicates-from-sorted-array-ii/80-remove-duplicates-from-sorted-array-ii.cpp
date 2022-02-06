class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=2,c=0;
        while(j<n){
            if(nums[j]!=nums[j-2-c]){
                nums[j-c]=nums[j];
            }else{
                    c++;
                }
            j++;
        }
    return n-c;
    }
};