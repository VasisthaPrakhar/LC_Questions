class Solution {
public:
    bool isPerfectSquare(int num) {
        int beg=1,end=pow(2,17);
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(num/mid==mid  && num%mid==0){
                return true;
            }else if(num/mid > mid){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
};