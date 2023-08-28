class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),k=n-1;
        while(j<n){
            if(nums[j]==0){
                if(j>i){
                    swap(nums[j],nums[i]);
                    j--;
                }
                i++;
            }else if(nums[j]==2){
                    if(j<k){
                        swap(nums[j],nums[k]);
                        j--;
                    }
                    k--;
                }
            j++;
        }
    }
};