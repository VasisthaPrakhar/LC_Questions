class Solution {
public:
    typedef long long int ll;
    bool check(vector<int>&p,int n, ll mid, int k){
        int prev=p[0],c=0;
        for(int i=1;i<n;i++){
            if(p[i]-prev>=mid){
                c++;
                prev=p[i];
            }
            if(c+1>=k){
                return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& p, int k) {
        int n=p.size();
        ll beg=0,end=1e9,mid,ans=0;
        sort(p.begin(),p.end());
        while(beg<end){
            mid=(beg+end)/2;
            if(check(p,n,mid,k)){
                beg=mid+1;
                //cout<<mid<<endl;
                ans=mid;
            }else{
                end=mid;
            }
        }
        return ans;
    }
};