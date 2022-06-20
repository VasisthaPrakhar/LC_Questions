class Solution {
public:
    long long numberOfWeeks(vector<int>& mi) {
        long long ma=0,sum=0;
        for(auto x:mi){
            sum+=x;
            ma=ma<x?x:ma;
        }
        long long int ans=2*(sum-ma);
        return min(ans+1,sum);
    }
};