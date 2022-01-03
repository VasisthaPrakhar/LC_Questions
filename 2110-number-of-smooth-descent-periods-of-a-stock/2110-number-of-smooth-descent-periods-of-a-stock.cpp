class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long c=0,ans=p.size();
        vector<long long int>v;
        for(int i=1;i<p.size();i++){
            if(p[i-1]-1==p[i]){
                c++;
            }else{
                if(c>0)
                v.push_back(c);
                c=0;
            }
        }
        if(c>0){
            v.push_back(c);
        }
        for(int i=0;i<v.size();i++){
            ans+=(v[i]*(v[i]+1))/2;
        }
        return ans;
    }
};