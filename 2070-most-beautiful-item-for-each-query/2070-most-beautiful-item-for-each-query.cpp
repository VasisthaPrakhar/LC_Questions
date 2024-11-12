class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) {
        int n=it.size(),ma=0;
        sort(it.begin(),it.end());
        unordered_map<int,int>mp;
        vector<int>a,ans;
        for(int i=0;i<n;i++){
            ma=max(ma,it[i][1]);
            a.push_back(it[i][0]);
            mp[i]=ma;
        }
        for(auto x:q){
            auto f=upper_bound(a.begin(),a.end(),x)-a.begin();
            if(f==0){
                ans.push_back(0);
            }else{
                ans.push_back(mp[f-1]);
            }
        }
        return ans;
    }
};