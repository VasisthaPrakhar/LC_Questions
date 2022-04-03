#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        int beg=0,end=n-1,ans=0;
        while(beg<=end){
            int mid=(beg+end)>>1;
            if(n-mid>c[mid]){
               // ans=n-mid;
                beg=mid+1;
            }else{
                ans=n-mid;
                end=mid-1;
            }
        }
        return ans;
    }
};