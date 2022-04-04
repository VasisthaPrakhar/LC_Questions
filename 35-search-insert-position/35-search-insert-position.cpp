class Solution {
public:
    int lower(vector<int>& nums, int ta){
        int n=nums.size();
        int beg=0,end=n-1,idx=-1;
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(nums[mid]==ta){
                idx=mid;
                break;
            }else if(nums[mid]>ta){
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return idx==-1?end+1:idx;
    }
    int searchInsert(vector<int>& nums, int target) {
        return lower(nums,target);
    }
};