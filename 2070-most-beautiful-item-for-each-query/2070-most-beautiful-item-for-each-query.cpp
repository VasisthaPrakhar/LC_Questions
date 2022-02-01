static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) {
        int n=it.size();
        int m=q.size();
        sort(it.begin(),it.end());
        map<int,int>mp;
        mp[0]=0;
        mp[it[0][0]]=it[0][1];
        int ma=0;
        for(int i=1;i<n;i++){
            it[i][1]=it[i][1]>it[i-1][1]?it[i][1]:it[i-1][1];
            mp[it[i][0]]=it[i][1];
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            if(!mp.count(q[i])){
                mp[q[i]]=0;
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            auto it1=it;
            it1--;
            if(it->second==0){
                it->second=it1->second;
            }
        }
        for(auto x:q){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};