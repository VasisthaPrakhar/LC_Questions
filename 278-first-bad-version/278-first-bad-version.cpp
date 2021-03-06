// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int beg=1,end=n,ans;
        while(beg<=end){
            int mid=(end-beg)/2 +beg;
            if(isBadVersion(mid)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};