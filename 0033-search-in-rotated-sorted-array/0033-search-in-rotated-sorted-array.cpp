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
            if(nums[mid]<target){
                if(nums[end]<nums[mid] || (nums[mid]<nums[end] && target<=nums[end])){
                    beg=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                if(nums[beg]>nums[mid] ||(target>=nums[beg] && nums[mid]>nums[beg])){
                    end=mid-1;
                }else{
                    beg=mid+1;
                }
            }
        }
        return -1;
    }
};