class Solution {
public:
    typedef long long int ll;
    ll fun(int idx, int n, vector<pair<int,int>>v, int prev){
        if(prev>=n){
            return 0;
        }
        if(idx>n){
            return INT_MAX;
        }
        ll res=INT_MAX,res1=INT_MAX;
        res1=fun(idx+1,n,v,prev);
        for(int i=idx+1;i<=n;i++ ){
            if(max(v[idx].second+1,prev+1) < v[i].first){
                break;
            }
            res = min(res,1+fun(i,n,v,max(v[idx].second,prev)));
        }
        // if(prev!=INT_MIN || (idx<n && v[idx+1].first<=0))
            
        return min(res,res1);
    }
    int minTaps(int n, vector<int>& r) {
        vector<pair<int,int>>v;
        for(int i=0;i<=n;i++){
            if(r[i]!=0)
                v.push_back({i-r[i],i+r[i]});
        }
        //sort(v.begin(),v.end());
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b)->bool{
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        int i=1;
        // for(auto x:v){
        //     cout<<i++<<" "<<x.first<<" "<<x.second<<endl;
        // }
        int m=v.size();
        int ans=0,j=0;
        for(int i=0;i<=n;i++){
            int idx=i,f=0;
            if(i!=0){idx--;}
            while(j<m && v[j].first<=idx){
                i=max(i,v[j].second);
                f=1;
                j++;
            }
            if((j>=m && i<n) || f==0){
                return -1;
            }
            //cout<<i<<" "<<j<<endl;
            ans++;
        }
        //ll ans=fun(0,n,v,INT_MIN);
        //cout<<ans<<endl;
        return ans==0?-1:ans;
    }
};