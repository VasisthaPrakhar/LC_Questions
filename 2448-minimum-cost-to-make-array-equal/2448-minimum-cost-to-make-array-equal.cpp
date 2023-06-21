typedef long long int ll;
class Solution {
public:
   ll f(ll curr, ll n, vector<int>&a, vector<int>&c)
    {
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(abs(curr-a[i]))*c[i];
        }
        return ans;
    }
    // bool check(vector<int>&s, vector<int>&c){
    //     int i=0,j=1;
    //     while(i<j){
    //         if(s[i]!=s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    long long minCost(vector<int>& a, vector<int>& c) {
        ll n=a.size();
        ll beg=-100000000, end=100000000;
        //check(a,c);
        while(beg<end)
        {
            ll mid=(beg+end)/2;
            ll sm=f(mid,n,a,c);
            ll su=f(mid+1,n,a,c);
            ll sl=f(mid-1,n,a,c);
            if(sm<su && sm<sl)return sm;
            if(su>sm)end=mid;
            else beg=mid+1;
        }
        return f(end,n,a,c);
    }
};