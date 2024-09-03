class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;
        for(auto x:s){
            int z=x-'a';
            z++;
            ans+=(z/10) + (z%10);
        }
        k--;
        while(k--){
            int t=0;
            while(ans){
                t+=ans%10;
                ans=ans/10;
            }
            ans=t;
        }
        return ans;
    }
};