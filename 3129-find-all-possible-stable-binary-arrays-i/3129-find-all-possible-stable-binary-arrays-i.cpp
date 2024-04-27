#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    typedef long long int ll;
    int mod=1e9+7;
    // bool check(vector<int>&a,int l, int n){
    //     int c0=0,c1=0;
    //     for(int i=0;i<min(l,n);i++){
    //         if(a[i]==0){
    //             c0++;
    //         }else{
    //             c1++;
    //         }
    //     }
    //     if(c1==0 || c0==0){
    //         return false;
    //     }
    //     int j=l,i=0;
    //     while(j<n){
    //         if(a[i]==0){
    //             c0--;
    //         }else{
    //             c1--;
    //         }
    //         if(a[j]==0){
    //             c0++;
    //         }else{
    //             c1++;
    //         }
    //         if(c1==0 || c0==0){
    //             return false;
    //         }
    //         j++,i++;
    //     }
    //     if(c1==0 || c0==0){
    //         return false;
    //     }
    //     return true;
    // }
    // ll fun(int idx,int n,int z,int o,int l,vector<int>&a){
    //     if(idx>=n){
    //         if(check(a,l+1,n))
    //             return 1;
    //         return 0;
    //     }
    //     ll res=0;
    //     if(z){
    //         a.push_back(0);
    //         res = res + fun(idx+1,n,z-1,o,l,a);
    //         a.pop_back();
    //     }
    //     if(o){
    //         a.push_back(1);
    //         res = res + fun(idx+1,n,z,o-1,l,a);
    //         a.pop_back();
    //     }
    //     return res;
    // }
    int dp[201][201][2][201];
    ll fun(int z,int o,int l,int p, int c){
        if(z<0 || o<0){
            return 0;
        }
        if(z<=0 && o<=0){
            return 1;
        }
        if(p!=-1 && dp[z][o][p][c]!=-1){
            return dp[z][o][p][c];
        }
        ll res=0;
        if(z>=0){
            if(p==0){
                if(c<l){
                    res = res + fun(z-1,o,l,0,c+1)%mod;
                }
            }else{
                res = res + fun(z-1,o,l,0,1)%mod;
            }
        }
        if(o>=0){
            if(p==1){
                if(c<l){
                    res = res + fun(z,o-1,l,1,c+1)%mod;
                }
            }else{
                res = res + fun(z,o-1,l,1,1)%mod;
            }
        }
        return dp[z][o][p][c] = res%mod;
    }
    
    int numberOfStableArrays(int z, int o, int limit) {
        memset(dp,-1,sizeof(dp));
        return fun(z,o,limit,0,0);
    }
};