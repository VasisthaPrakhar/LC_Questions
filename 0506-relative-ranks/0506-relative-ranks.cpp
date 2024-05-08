class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
        int n=s.size();
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            a.push_back({s[i],i});
        }
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[a[i].second]="Gold Medal";
            }else if(i==1){
                ans[a[i].second]="Silver Medal";
            }else if(i==2){
                ans[a[i].second]="Bronze Medal";
            }else{
                ans[a[i].second]=to_string(i+1);
            }
        }
        return ans;
    }
};