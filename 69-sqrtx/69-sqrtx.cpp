class Solution {
public:
    int mySqrt(int x) {
        int beg=0,end=46340,ans;
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(mid*mid<=x){
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};