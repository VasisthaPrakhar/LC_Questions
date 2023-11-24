class Solution {
public:
    int maxCoins(vector<int>& p) {
        int n=p.size();
        if(n==3){return p[1];}
        int j=n-2,i=0,ans=0;
        sort(p.begin(),p.end());
        while(j>i){
            ans+=p[j];
            j-=2;
            i++;
        }
        return ans;
    }
};