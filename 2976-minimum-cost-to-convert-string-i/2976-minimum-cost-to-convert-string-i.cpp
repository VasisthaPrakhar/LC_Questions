class Solution {
public:
    typedef long long int ll;
    long long minimumCost(string s, string t, vector<char>& og, vector<char>& ch, vector<int>& cost) {
        int n=og.size();
        vector<vector<ll>>adj(26,vector<ll>(26,INT_MAX));
        for(int i=0;i<n;i++){
            adj[og[i]-'a'][ch[i]-'a']=min(adj[og[i]-'a'][ch[i]-'a'], (ll)cost[i]);
        }
        // for(int i=0;i<26;i++){
        //     adj[i][i]=0;
        // }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][j] > adj[i][k] + adj[k][j] ){
                        adj[i][j] = (adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
        int m=s.length();
        ll ans=0;
        for(int i=0;i<m;i++){
            if(s[i]!=t[i]){
                if(adj[s[i]-'a'][t[i]-'a']==INT_MAX){
                    return -1;
                }
                ans+=adj[s[i]-'a'][t[i]-'a'];
            }
        }
        return ans;
    }
};