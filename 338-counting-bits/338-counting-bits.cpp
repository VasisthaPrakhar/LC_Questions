class Solution {
public:
    int fun(int n){
        int ans=0;
        while(n){
            if(n&1){ans++;}
            n=n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=fun(i);
        }
        return ans;
    }
};