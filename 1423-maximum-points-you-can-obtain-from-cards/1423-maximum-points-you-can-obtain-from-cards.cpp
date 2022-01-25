class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n=c.size();
        int p[n];
        p[0]=c[0];
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+c[i];
        }
        if(k==1){
            return max(p[0],p[n-1]-p[n-2]);
        }
        if(n==k){
            return p[n-1];
        }
        int ans=p[n-1]-p[(n-1-k)];
        for(int i=1;i<=k;i++){
            int s=p[i-1]+(p[n-1]-p[n-1-k+i]);
            ans=ans>s?ans:s;
        }
        return ans;
    }
};