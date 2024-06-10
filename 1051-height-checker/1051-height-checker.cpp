class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>a=h;
        int ans=0;
        sort(h.begin(),h.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=h[i]){
                ans++;
            }
        }
        return ans;
    }
};