class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int beg=0,end=n-1;
            int k=beg;
            while(k<end && a[k]==a[k+1]){
                k++;
            }
            beg=k;
            k=end;
            while(k>beg && a[k]==a[k-1]){
                k--;
            }
            end=k;
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