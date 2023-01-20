class Solution {
public:   
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<int>b;
        sort(a.begin(), a.end());
        vector<vector<int>>ans;
        set<vector<int>>res;
        int n=a.size();
        int lim=pow(2,n);
        for(int i=0;i<lim;i++){
            vector<int>b;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    b.push_back(a[j]);
                }
            }
            res.insert(b);
        }
        for(auto x:res){
            ans.push_back(x);
        }
        return ans;
    }
};