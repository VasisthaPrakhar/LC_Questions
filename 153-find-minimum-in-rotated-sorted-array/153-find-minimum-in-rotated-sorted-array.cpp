class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int beg=0,end=n-1;
        while(beg<end){
            int mid=(beg+end)/2;
            if(a[mid]>a[end] && a[mid]>=a[beg]){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        return a[beg];
    }
};