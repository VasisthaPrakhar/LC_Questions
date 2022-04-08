class Solution {
public:
    bool fun(long long int mid,int n){
        return (mid*(mid+1))/2<=n;
    }
    int arrangeCoins(int n) {
        int beg=1,end=100000,ans;
        while(beg<=end){
            long long int mid=(beg+end)>>1;
            if(fun(mid,n)){
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};