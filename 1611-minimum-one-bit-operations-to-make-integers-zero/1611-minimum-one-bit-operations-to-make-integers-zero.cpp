class Solution {
public:
    typedef long long int ll;
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }
        vector<ll>pre(32,0);
        pre[0]=1;
        pre[1]=3;
        for(int i=2;i<32;i++){
            pre[i]=2*pre[i-1]+1;
        }
        vector<int>a;
        while(n){
            a.push_back(n%2);
            n/=2;
        }
        int m=a.size();
        ll ans=0;
        //cout<<ans<<" "<<m;
        for(int i=0;i<m;i++){
            if(a[i]>0){
                ans=pre[i]-ans;
            }
        }
        return ans;
    };
};