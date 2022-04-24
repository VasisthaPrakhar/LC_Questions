class UndergroundSystem {
    private: unordered_map<int,pair<string,int>>m;
    map<pair<string,string>,double>m1,m2;
public:
    UndergroundSystem() {
        m.clear();
        m1.clear();
    }
    
    void checkIn(int id, string sn, int t) {
        m[id]={sn,t};
    }
    
    void checkOut(int id, string sn, int t) {
        if(m1.count({m[id].first,sn}))
            m1[{m[id].first,sn}]=(double)(m1[{m[id].first,sn}]+(double)(t-m[id].second));
        else
            m1[{m[id].first,sn}]=(t-m[id].second)*1.0;
        m2[{m[id].first,sn}]++;
        m.erase(id);
    }
    
    double getAverageTime(string sn, string en) {
        return m1[{sn,en}]/m2[{sn,en}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */