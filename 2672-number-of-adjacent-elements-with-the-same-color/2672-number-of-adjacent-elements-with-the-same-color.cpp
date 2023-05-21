class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& qu) {
        vector<int>a(n,0),res(qu.size(),0);
        if(n==1){
            return res;
        }
        int ans=0,i=0;
        for(auto x:qu){
            int idx=x[0];
            int nc=x[1];
            int right=0,left=0;
            if(idx>0){
                left=a[idx-1];
            }
            if(idx<n-1){
                right=a[idx+1];
            }
            int old=a[idx];
            a[idx]=nc;
            if(old!=0 && old==left){
                ans--;
            }
            if(old!=0 && old==right){
                ans--;
            }
            if(nc!=0 && nc==left){
                ans++;
            }
            if(nc!=0 && nc==right){
                ans++;
            }
            res[i++]=ans;
        }
        return res;
    }
};