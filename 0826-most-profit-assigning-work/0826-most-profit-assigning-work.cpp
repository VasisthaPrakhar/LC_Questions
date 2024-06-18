class Solution {
public:
    int upper(vector<pair<int,int>>&a,int n,int x){
        int beg=0,end=n-1;
        while(beg<end){
            int mid=(beg+end)/2;
            if(a[mid].first<=x){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        if(beg < n && a[beg].first <= x) {
           beg++;
        }
        return beg;
    }
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n=d.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){v.push_back({d[i],p[i]});}
        vector<int>k(n,0);
        sort(v.begin(),v.end());
        int ma=0;
        for(int i=0;i<n;i++){
            k[i]=ma;
            ma=max(v[i].second,ma);
        }
        int ans=0;
        for(auto &x:w){
            int f=upper(v,n,x);
            if(f==n){
                ans+=ma;
            }else{
                ans+=k[f];
            }
        }
        return ans;
    }
};