class FoodRatings {
private:
    unordered_map<string,pair<int,string>>m;
    unordered_map<string,map<int,set<string>,greater<int>>>mc;
public:
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int n=f.size();
        for(int i=0;i<n;i++){
            m[f[i]]={r[i],c[i]};
            mc[c[i]][r[i]].insert(f[i]);
        }
    }
    
    void changeRating(string food, int nr) {
        auto temp=m[food];
        mc[temp.second][temp.first].erase(food);
        if(mc[temp.second][temp.first].size()==0){
            mc[temp.second].erase(temp.first);
        }
        mc[temp.second][nr].insert(food);
        m[food].first=nr;
    }
    
    string highestRated(string c) {
        return *(mc[c].begin()->second).begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */