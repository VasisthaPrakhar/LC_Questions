class Solution {
public:
    bool isPathCrossing(string path) {
        map<char,pair<int,int>>m;
        m['N']={0,1};
        m['E']={1,0};
        m['W']={-1,0};
        m['S']={0,-1};
        int a=0,b=0;
        set<pair<int,int>>s;
        s.insert({0,0});
        for(auto x:path){
            a=a+m[x].first;
            b=b+m[x].second;
            if(s.find({a,b})!=s.end()){
                return true;
            }
            s.insert({a,b});
        }
        return false;
    }
};