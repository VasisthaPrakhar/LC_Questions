#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int fun(string &s, int &k,char ch){
        int n=s.length(),ma=0,j=0,i=0,z=0;
        while(j<n){
            if(s[j]!=ch){
                z++;
            }
            while(i<=j && z>k){
                if(s[i]!=ch){
                    z--;
                }
                i++;
            }
            ma=max(j-i+1,ma);
            j++;
        }
        return ma;
    }
    int maxConsecutiveAnswers(string &a, int k) {
        return max(fun(a,k,'T'),fun(a,k,'F'));
    }
};