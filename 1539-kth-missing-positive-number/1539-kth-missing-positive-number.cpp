class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]){
            return k;
        }
        int n=arr.size();
        int beg=0,end=n-1,ans;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(arr[mid]-(mid+1)<k){
                //ans=beg;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return beg+k;
    }
};