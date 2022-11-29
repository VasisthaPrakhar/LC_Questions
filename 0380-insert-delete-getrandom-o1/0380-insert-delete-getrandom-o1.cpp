class RandomizedSet {
    private:
    unordered_set<int>s;
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return false;
        }
        else{
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            s.erase(val);
            return true;
        }
        else{            
            return false;
        }
    }
    
    int getRandom() {
        int idx=rand()%s.size();
        auto it=s.begin();
        for(int i=0;i<idx;i++){
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */