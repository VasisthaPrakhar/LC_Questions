class Solution {
public:
    int lower(vector<int>& a, int t,int n){
        int beg=0,end=n-1,pos=-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(a[mid]==t){
                pos=mid;
            }
            if(a[mid]<t){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return pos;
    }
    int upper(vector<int>& a, int t,int n){
        int beg=0,end=n-1,pos=-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(a[mid]==t){
                pos=mid;
            }
            if(a[mid]<=t){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        return {lower(nums,target,n),upper(nums,target,n)};
    }
};