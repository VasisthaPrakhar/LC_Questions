class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n=d.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){v.push_back({d[i],p[i]});}
        vector<int>k(n,0);
        sort(v.begin(),v.end());
        sort(d.begin(),d.end());
        int ma=0;
        for(int i=0;i<n;i++){
            k[i]=ma;
            ma=max(v[i].second,ma);
        }
        int ans=0;
        for(auto x:w){
            auto f=upper_bound(d.begin(),d.end(),x)-d.begin();
            if(f==n){
                ans+=ma;
            }else{
                ans+=k[f];
            }
        }
        return ans;
    }
};