class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n=a.size();
        int lim=pow(2,n);
        vector<vector<int>>ans;
        for(int i=0;i<lim;i++){
            vector<int>b;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    b.push_back(a[j]);
                }
            }
            ans.push_back(b);
        }
        return ans;
    }
};