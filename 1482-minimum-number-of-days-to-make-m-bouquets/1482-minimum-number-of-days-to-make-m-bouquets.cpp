class Solution {
public:
    typedef long long int ll;
    bool check(vector<int>&a,int x,int n ,int k,int m){
        int i=0,j=0;
        while(i<n){
            if(a[i]<=x){
                int z=0;
                while(i<n && a[i]<=x){
                    z++,i++;
                }
                j+=z/k;
                i--;
            }
            if(j>=m){break;}
            i++;
        }
        return j>=m;
    }
    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();
        ll z=(ll)m*(ll)k;
        if(z>n){return -1;}
        int beg=1,end=1e9+1,mid,ans=-1;
        while(beg<end){
            mid=(beg+end)/2;
            if(check(b,mid,n,k,m)){
                ans=mid;
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};