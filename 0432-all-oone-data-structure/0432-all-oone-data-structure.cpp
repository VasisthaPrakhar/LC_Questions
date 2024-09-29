class AllOne {
private:
    unordered_map<string,int>a;
    map<int,set<string>>b;
public:
    AllOne() {
        a.clear();
        b.clear();
    }
    
    void inc(string key) {
        if(a.find(key)!=a.end()){
            b[a[key]].erase(key);
            if(b[a[key]].size()==0){
                b.erase(a[key]);
            }
        }
        a[key]++;
        b[a[key]].insert(key);
    }
    
    void dec(string key) {
        b[a[key]].erase(key);
        if(b[a[key]].size()==0){
            b.erase(a[key]);
        }
        a[key]--;
        if(a[key]>0){
            b[a[key]].insert(key);
        }else{
            a.erase(key);
        }
    }
    
    string getMaxKey() {
        if(b.size()){
            auto it=b.end();
            it--;
            return *((it->second).begin());
        }
        return "";
    }
    
    string getMinKey() {
        if(b.size()){
            return *(b.begin()->second.begin());
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */