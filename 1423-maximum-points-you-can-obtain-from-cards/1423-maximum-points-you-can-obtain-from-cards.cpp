class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        vector<int>p;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=c[i];
            p.push_back(sum);
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
            ans=max(ans,s);
        }
        return ans;
    }
};