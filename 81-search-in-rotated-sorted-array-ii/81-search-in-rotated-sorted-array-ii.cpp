class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // int beg=0,end=a.size()-1;
        // while(beg<=end){
            // while(beg<end && a[beg+1]==a[beg]){
            //     beg++;
            // }
            // while(end>beg && a[end-1]==a[end]){
            //     end--;
            // }
        //     int mid=(beg+end)/2;
        //     if(a[mid]==tar){
        //         return true;
        //     }
        //     if(a[mid]<tar){
        //         if(a[beg]<=a[mid] || a[beg]>tar){
        //             beg=mid+1;
        //         }else{
        //             end=mid-1;
        //         }
        //     }else{
        //         if(a[beg]>a[mid] || a[beg]<=tar){
        //             end=mid-1;
        //         }else{
        //             beg=mid+1;
        //         }
        //     }
        // }
        // return false;
         int n=nums.size();
        int beg=0,end=n-1;
        while(beg<=end){
             while(beg<end && nums[beg+1]==nums[beg]){
                beg++;
            }
            while(end>beg && nums[end-1]==nums[end]){
                end--;
            }
            int mid=(beg+end)/2;
            if(nums[mid]==target){
                return true;
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
        return false;
    }
};