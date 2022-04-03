#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        int beg=1,end=1000,ans;
        while(beg<=end){
            int mid=(beg+end)>>1;
            auto f=lower_bound(c.begin(),c.end(),mid)-c.begin();
            if(n-f>=mid){
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};