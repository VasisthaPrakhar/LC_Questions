class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int beg=0,end=n-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if((nums[mid]>=nums[0] && target>=nums[0]) || (nums[mid]<nums[0] && target<nums[0])){
                if(target>nums[mid]){
                    beg=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                if(nums[mid]<nums[0]){
                    end=mid-1;
                }else{
                    beg=mid+1;
                }
            }
            
        }
        return -1;
    }
};