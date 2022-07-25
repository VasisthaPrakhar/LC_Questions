class NumberContainers {
    unordered_map<int,int>m;
    map<int,set<int>>m1;
public:
    NumberContainers() {
        m.clear();
        m1.clear();
    }
    
    void change(int index, int number) {
        if(m.count(index)){
            int k=m[index];
            m1[k].erase(index);
            if(m1[k].size()==0){
                m1.erase(k);
            }
        }
        m1[number].insert(index);
        m[index]=number;
    }
    
    int find(int number) {
        if(m1.find(number)!=m1.end()){
            return *m1[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */