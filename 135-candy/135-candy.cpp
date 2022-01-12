class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        if(n==1){
            return 1;
        }
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1] && ans[i]<=ans[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1] && ans[i]<=ans[i+1]){
                ans[i]=ans[i+1]+1;
            }
        }
        long long int res=0;
        for(auto x:ans){
            res+=x;
        }
        return res;
    }
};