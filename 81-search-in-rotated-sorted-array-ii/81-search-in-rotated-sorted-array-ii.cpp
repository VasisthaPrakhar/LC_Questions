class Solution {
public:
    bool search(vector<int>& a, int tar) {
        int n=a.size();
        int beg=0,end=n-1;
        while(beg<=end){
            while(beg<end && a[beg+1]==a[beg]){
                beg++;
            }
            while(end>beg && a[end-1]==a[end]){
                end--;
            }
            int mid=(beg+end)/2;
            cout<<mid<<" ";
            if(a[mid]==tar){
                return true;
            }
            if(a[mid]<tar){
                if(a[beg]<=a[mid] || a[beg]>tar){
                    beg=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                 if (a[beg] > a[mid] || a[beg] <= tar) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            }
        }
        return false;
    }
};