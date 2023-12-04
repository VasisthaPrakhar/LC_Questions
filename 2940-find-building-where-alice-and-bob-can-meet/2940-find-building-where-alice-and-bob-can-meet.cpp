#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n=h.size(),m=q.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={h[i],i};
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b)->bool{
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        set<int>s;
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            // s.insert(v[i].second);
            // auto f=s.upper_bound(v[i].second);
            // mp1[v[i].second].insert(v[i].second);
            // for(auto it=f;it!=s.end();it++){
            //     if(h[*it]>v[i].first){
            //         mp1[v[i].second].insert(*it);
            //     }
            // }
            mp[v[i].second]=i;
        }
        map<int,set<int>>mp1;
        vector<int>ans(m);
        int j=0;
        for(int i=0;i<m;i++){
            int res=INT_MAX;
            int a,b;
            if(q[i][0]<q[i][1]){
                a=q[i][0],b=q[i][1];
            }else{b=q[i][0],a=q[i][1];}
            int ma=max(h[a],h[b]);
            if(a==b){
                ans[j++]=a;
                continue;
            }
            if(h[a]==h[b]){
                for(int i=mp[b]+1;i<n;i++){
                    if(v[i].second>b && v[i].first>h[a]){
                        res=min(v[i].second,res);
                    }
                }
                if(res==INT_MAX){
                    res=-1;
                }
            }else if(h[a]>h[b]){
                for(int i=mp[a];i<n;i++){
                    if(v[i].second>b && v[i].first>h[a]){
                        res=min(v[i].second,res);
                    }
                }
                if(res==INT_MAX){
                    res=-1;
                }
                // for(int i=mp[b]+1;i<n;i++){
                //     if(v[i].second>b && v[i].first>h[a]){
                //         res=min(v[i].second,res);
                //     }
                // }
                // if(res==INT_MAX){
                //     res=-1;
                // }
            }else{
                res=b;
            }
            mp1[ma].insert(res);
            ans[j++]=res;
           // mp[a][b]=res;
        }
        return ans;
    }
};
