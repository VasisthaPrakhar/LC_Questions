class Solution {
public:
    bool fun(long long int n, vector<int>& b, long long int time){
        long long int tt=time*n;
        for(auto x:b){
            tt=tt-min((long long int)x,time);
        }
        return tt<=0;
    }
    long long maxRunTime(int n, vector<int>& b) {
        long long int beg=0,end=1e14,mid,ans=0;
        while(beg<=end){
            mid=(beg+end)/2;
            if(fun(n,b,mid)){
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};