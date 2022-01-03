static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long c=0,ans=p.size();
        for(int i=1;i<p.size();i++){
            if(p[i-1]-1==p[i]){
                c++;
            }else{
                if(c>0)
                ans+=(c*(c+1))/2;
                c=0;
            }
        }
        if(c>0){
            ans+=(c*(c+1))/2;
        }
        return ans;
    }
};