class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size(),c=0;
        vector<int>mi(n,0),ma(n,0);
        map<int,int>m;
        for(int i=n-1;i>=0;i--){
            m[r[i]]++;
            c++;
            int k=0;
            for(auto x:m){
                if(x.first==r[i]){break;}
                k+=x.second;
            }
            mi[i]=k;
            ma[i]=c-m[r[i]]-k;
        }
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(r[i]<r[j]){
                    ans+=ma[j];
                }
                if(r[i]>r[j]){
                    ans+=mi[j];
                }
            }
        }
        return ans;
    }
};