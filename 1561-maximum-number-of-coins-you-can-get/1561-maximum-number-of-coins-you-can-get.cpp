class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(),p.end());
        int ans=0,n=p.size();
        int j=n-2,i=0;
        while(j>i){
            ans+=p[j];
            j-=2;
            i++;
        }
        return ans;
    }
};