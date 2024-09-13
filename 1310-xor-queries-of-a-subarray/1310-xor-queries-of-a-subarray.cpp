class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int a=0,n=arr.size();
        vector<int>pre(n,0),suf(n,0);
        for(int i=0;i<n;i++){
            pre[i]=a;
            a=a^arr[i];
        }
        a=0;
        for(int i=n-1;i>=0;i--){
            suf[i]=a;
            a^=arr[i];
        }
        vector<int>ans;
        for(auto &x:q){
            ans.push_back((a^pre[x[0]])^suf[x[1]]);
        }
        return ans;
    }
};