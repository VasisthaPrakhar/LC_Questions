class Solution {
public:
    string destCity(vector<vector<string>>& p) {
        int n=p.size();
        map<string,int>m;
        for(int i=0;i<n;i++){
            m[p[i][0]]+=2;
            m[p[i][1]]++;
        }
        for(auto x:m){
            if(x.second==1){
                return x.first;
            }
        }
        return "";
    }
};