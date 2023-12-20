class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        if(p[0]+p[1]<=m){
            return m-(p[0]+p[1]);
        }
        return m;
    }
};