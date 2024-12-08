class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int n=e.size();
        sort(e.begin(),e.end());
        map<int,int>mp;
        vector<int>a(n,0);
        int k=0,ma=0,ans=0;
        for(auto x:e){
            if(mp.count(x[0])){
                a[mp[x[0]]]=max(x[2],a[mp[x[0]]]);
            }else{
                mp[x[0]]=k;
                a[k++]=x[2];
            }
        }
        for(int i=k-1;i>=0;i--){
            ma=max(ma,a[i]);
            a[i]=ma;
        }
        for(int i=0;i<n;i++){
            int res=e[i][2];
            auto f=mp.upper_bound(e[i][1]);
            if(f!=mp.end()){
                res+=a[f->second];
            }
            ans=max(ans,res);
        }
        return ans;
    }
};