class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int t) {
        int n=c.size();
        vector<bool>ans(n,false);
        int ma=*max_element(c.begin(),c.end());
        for(int i=0;i<n;i++){
            if(c[i]==ma){
                ans[i]=true;
            }else if(c[i]+t>=ma){
                ans[i]=true;
            }
        }
        return ans;
    }
};