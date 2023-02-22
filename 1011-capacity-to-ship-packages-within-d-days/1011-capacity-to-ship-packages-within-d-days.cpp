class Solution {
public:
    bool fun(vector<int>&w,int d,int mid,int n){
        int s=0,day=0;
        for(int i=0;i<n;i++){
            if(s+w[i]>mid){
                s=w[i];
                day++;
            }else{
                s+=w[i];
            }
        }
        return day<d;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int beg=*max_element(w.begin(),w.end()),end=1e9,mid,ans,n=w.size();
        while(beg<=end){
            mid=(beg+end)/2;
            if(fun(w,d,mid,n)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};