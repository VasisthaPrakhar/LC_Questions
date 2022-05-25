class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n=(int)e.size();
        sort(e.begin(),e.end(),[](vector<int>&a,vector<int>&b)->bool{
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int>ans;
        for(auto x:e){
            auto it=lower_bound(ans.begin(),ans.end(),x[1]);
            if(it==ans.end()){
                ans.push_back(x[1]);
            }else if(x[1]<*it){
                *it=x[1];
            }
        }
        return ans.size();
    }
};