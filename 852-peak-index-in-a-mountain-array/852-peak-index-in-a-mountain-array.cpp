class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int beg=0,end=n-1;
        while(beg<end){
            int mid=(beg+end)>>1;
            if(arr[mid]<=arr[mid+1]){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        return beg;
    }
};