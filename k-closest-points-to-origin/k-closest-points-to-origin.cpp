class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
     map<long long int,vector<pair<int,int>>>m;
        for(int i=0;i<p.size();i++){
            m[pow(p[i][0],2)+pow(p[i][1],2)].push_back({p[i][0],p[i][1]});
        }
        long long int cnt=0;
        vector<vector<int>>ans;
        for(auto it=m.begin();it!=m.end();it++){
            for(auto x:it->second){
                ans.push_back({x.first,x.second});
                cnt++;
                if(cnt==k){
                    return ans;
                }
            }
        }
        return {};
    }
};