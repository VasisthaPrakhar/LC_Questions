class Solution {
public:
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>m;
        for(auto &x:deck){
            m[x]++;
        }
        int res=0;
        for(auto it:m){
            res=gcd(it.second,res);
        }
        if(res<2){
            return false;
        }
        return true;
    }
};