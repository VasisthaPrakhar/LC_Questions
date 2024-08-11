class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& c) {
        map<string,pair<int,int>>mp;
        mp["RIGHT"]={0,1};
        mp["DOWN"]={1,0};
        mp["UP"]={-1,0};
        mp["LEFT"]={0,-1};
        pair<int,int>p={0,0};
        for(auto x:c){
            p.first+=mp[x].first;
            p.second+=mp[x].second;
        }
        return (p.first*n)+p.second;
    }
};