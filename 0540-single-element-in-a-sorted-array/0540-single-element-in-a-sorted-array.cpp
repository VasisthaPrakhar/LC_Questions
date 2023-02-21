class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int beg=0,end=n-1,ans=0;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(mid%2!=0){mid--;}
            if(mid<n-1 && nums[mid+1]==nums[mid]){
                beg=mid+2;
            }else{
                end=mid-1;
                ans=nums[mid];
            }
        }
        return ans;
    }
};