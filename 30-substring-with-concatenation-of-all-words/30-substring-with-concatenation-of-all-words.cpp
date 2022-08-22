#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        int n=s.length();
        int m=w.size();
        int sz=w[0].size();
        if(sz*m>n){
            return {};
        }
        vector<int>ans;
        unordered_map<string,int>st,vis;
        for(auto x:w){
            st[x]++;
        }
        int j=0,i=0,f=0;
        while(j<=n-sz){
            string temp=s.substr(j,sz);
            f=0;
            if(st.find(temp)!=st.end()){
                vis.clear();
                i=j;
                while(i<=n-sz && st.find(temp)!=st.end() && vis.size()<m && vis[temp]<st[temp]){
                    vis[temp]++;
                    i+=sz;
                    f=1;
                    temp=s.substr(i,sz);
                }
               // cout<<vis.size();
                if(vis==st){
                    ans.push_back(j);
                }
            }
            j++;
        }
        return ans;
    }
};