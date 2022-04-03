class Solution {
public:
     int fun(vector<int>& c) {
        int n=c.size();
        int beg=1,end=1000,ans=0;
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
    int hIndex(vector<int>& c) {
        int n=c.size();
        sort(c.begin(),c.end());
        return fun(c);
    }
};