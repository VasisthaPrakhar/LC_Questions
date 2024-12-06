class Solution {
public:
    int maxCount(vector<int>& b, int n, int ms) {
        vector<int>v(n+1,1);
        for(int i=0;i<b.size();i++){
            if(b[i]<=n)
                v[b[i]]=0;
        }
        int ans=0;
        long int sum=0;
        for(int i=1;i<=n;i++){
            if(v[i]){
                sum+=i;
                if(sum<=ms){
                    ans++;
                }
            }
        }
        return ans;
    }
};