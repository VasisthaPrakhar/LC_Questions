#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int beg=0,end=n-1;
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
};