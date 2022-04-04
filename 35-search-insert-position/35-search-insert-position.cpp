class Solution {
public:
    int lower(vector<int>& nums, int ta){
        int n=nums.size();
        int beg=0,end=n-1;
        while(beg<end){
            int mid=(beg+end)>>1;
            if(nums[mid]==ta){
                return mid;
            }else if(nums[mid]>ta){
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return beg;
    }
    int searchInsert(vector<int>& nums, int target) {
        int idx=lower(nums,target);
        return (nums[idx]<target)?++idx:idx;
    }
};