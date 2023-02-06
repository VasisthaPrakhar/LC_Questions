class Solution {
public:
    map<int,int> fun(vector<int>&a,int sz,int n){
        map<int,int>m,m1;
        int c=0,ans=INT_MIN,l=-1;
        for(int i=0;i<n;i++){
            if(a[i]==-1){
                continue;
            }else{
                if(m.empty() || a[i]-m.begin()->first<=sz){
                    m[a[i]]++;
                    c++;
                }else{
                    m1[m.begin()->first]=c;
                    c-=m.begin()->second;
                    int z=m.begin()->first;
                    m.erase(z);
                    i--;
                }
            }
        }
        m1[m.begin()->first]=c;
        return m1;
    }
    int maximizeWin(vector<int>& p, int k) {
        int n=p.size();
        if(2*k+1>=(p.back()-p[0])){
            return n;
        }
        
        map<int,int>a=fun(p,k,n),b;
        vector<pair<int,int>>v;
        for(auto x:a){
            v.push_back({x.first,x.second});
        }
        int m=v.size(),ma=0;
        for(int i=m-1;i>=0;i--){
            ma=max(ma,v[i].second);
            b[v[i].first]=ma;
        }
        int ans=0;
        for(auto x:a){
            int g=x.first+k+1;
            int z=b.lower_bound(g)->second;
            ans=max(ans,x.second+z);
        }
        return ans;
    }
};