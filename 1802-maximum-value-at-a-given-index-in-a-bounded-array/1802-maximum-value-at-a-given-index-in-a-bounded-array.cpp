class Solution {
public:
    typedef long long int ll;
    ll su(ll n){
        if(n<0){
            return 0;
        }
        return (n*(n+1))/2;
    }
    bool check(int k,int n, int ma, int j){
        ll sum=k,z=k-1,x=k-1;
        if(j>=z){
            sum+=su(z)+(j-z);
        }else{
            sum+=((z*j)-su(j-1));
        }
        if((n-j-1)>=x){
            sum+=su(x)+((n-j-1)-x);
        }else{
            sum+=((x*(n-j-1))-su(n-j-2));
        }
        //cout<<k<<" "<<sum<<" "<<j<<endl;
        return sum<=ma;
    }
    int maxValue(int n, int index, int maxSum) {
        int beg=1,end=maxSum,ans=0;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(check(mid,n,maxSum,index)){
                beg=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};