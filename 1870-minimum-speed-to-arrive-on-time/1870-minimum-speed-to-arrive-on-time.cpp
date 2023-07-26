class Solution {
public:
    bool check(vector<int>& d, double h, int n, double mid){
        double sum=0;
        for(int i=0;i<n-1;i++){
            double temp=(double)d[i]/mid;
            sum+=ceil(temp);
        }
        sum+=(double)d[n-1]/mid;
        return sum<=h;
    }
    int minSpeedOnTime(vector<int>& d, double h) {
        int beg=1,end=1e9+7,mid,ans=-1,n=d.size();
        while(beg<end){
            mid=(beg+end)/2;
            if(check(d,h,n,mid)){
                ans=mid;
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};