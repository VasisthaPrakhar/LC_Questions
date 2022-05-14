class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        int n=tiles.size();
        sort(tiles.begin(),tiles.end());
        map<int,vector<int>>m;
        pair<int,int>p={tiles[0][0],tiles[0][1]};
        int sum=0;
        for(int i=1;i<n;i++){
            if(tiles[i][0]==p.second+1){
                p.second=tiles[i][1];
            }else{
                sum+=p.second-p.first+1;
                m[p.first]={p.first,p.second,sum};
                p.first=tiles[i][0];
                p.second=tiles[i][1];
            }
        }
        sum+=p.second-p.first+1;
        m[p.first]={p.first,p.second,sum};
        int s=0,f=1,ans=0;
        for(auto x:m){
            int k=x.first+len-1;
            auto it=m.lower_bound(k);
            //cout<<x.first<<" "<<ans<<endl;
            if(it==m.end()){
                it--;
                vector<int>a=(*it).second;
                ans=max(ans,a[2]-s);
                f=1;
            }
            else if((*it).first==k){
                vector<int>a=(*it).second;
                ans=max(ans,a[2]-(a[1]-a[0])-s);
            }else{
                it--;
                vector<int>a=(*it).second;
                if(a[1]<=k){
                    ans=max(ans,a[2]-s);
                }else{
                    ans=max(ans,a[2]-(a[1]-k)-s);
                }
            }
            // if(f){
            //     break;
            // }
            s=x.second[2];
        }
        return ans;
    }
};