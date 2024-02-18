class Solution {
public:
    typedef long long int ll;
    int dr[8]={0,0,1,-1,1,1,-1,-1};
    int dc[8]={1,-1,0,0,1,-1,1,-1};
    unordered_set<ll> fun(int n){
       vector<bool> prime(n + 1, true);
       prime[0] = false;
       prime[1] = false;
       ll m = sqrt(n);

       for (ll p = 2; p <= m; p++) {
           if (prime[p]) {
               for (ll i = p * 2; i <= n; i += p)
                   prime[i] = false;
           }
       }
       unordered_set<ll> ans;
       for (ll i = 0; i <= n; i++)
           if (prime[i])
               ans.insert(i);
           return ans;

    }
    bool check(int N){
        int flag = 1; 
        double sqroot = sqrt(N); 
        for (int i = 2; i <= sqroot; i++) { 
            if (N % i == 0) { 
                flag = 0; 
                break; 
            }
        }
        if(flag){return true;}
        return false;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        //unordered_set s=fun(pow(10,max(n,m)));
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<8;k++){
                    int r=i,c=j,num=0;
                    while(r<n && r>=0 && c<m && c>=0){
                        num=num*10 + mat[r][c];
                        if(num>10 && check(num)){
                            mp[num]++;
                        }
                        r+=dr[k];
                        c+=dc[k];
                    }
                }
            }
        }
        int ma=0,ans=-1;
        for(auto x:mp){
            if(x.second>=ma){
                ma=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};