class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]){
            return k;
        }
        int n=arr.size();
        int beg=0,end=n;
        while(beg<end){
            int mid=(beg+end)>>1;
            if(arr[mid]-1-mid<k){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        return beg+k;
    }
};