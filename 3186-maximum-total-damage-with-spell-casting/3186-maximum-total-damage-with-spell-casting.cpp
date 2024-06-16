class Solution {
public: 
    typedef long long int ll;
    long long maximumTotalDamage(vector<int>& p) {
        int n=p.size();
        sort(p.begin(),p.end());
        vector<ll>dp(n,0),ma(n,0);
        map<int,int,greater<int>>mp;
        ll ans=p[0];
        dp[0]=p[0];
        ma[0]=dp[0];
        mp[p[0]]=0;
        for(int i=1;i<n;i++){
            if(p[i]==p[i-1]){
                dp[i]+=dp[i-1]+p[i];   
            }else{
                auto it=mp.begin();
                int f=0;
                while(it != mp.end()){
                    if(it->first <= p[i]-3){
                        dp[i]+=ma[it->second]+p[i];
                        f=1;
                        break;
                    }
                    it++;
                }
                if(f==0){
                    dp[i]=p[i];
                }
            }
            ans=max(dp[i],ans);
            ma[i]=max(ans,ma[i-1]);
            mp[p[i]]=i;
        }
        return ans;
    }
};