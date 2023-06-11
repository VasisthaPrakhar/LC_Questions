class SnapshotArray {
private: vector<int>a;
    int c;
    map<int,map<int,int>>m;
public:
    SnapshotArray(int length) {
        a.resize(length,0);
        c=0;
        m.clear();
    }
    
    void set(int index, int val) {
        a[index]=val;
        m[index][c]=val;
    }
    
    int snap() {
        c++;
        return c-1;
    }
    
    int get(int index, int snap_id) {
        if(m.count(index)){
            if(m[index].count(snap_id)){
                return m[index][snap_id];
            }else{
                auto k=m[index];
                auto f=k.lower_bound(snap_id);
                if(f==k.begin()){
                    return 0;
                }else{
                    f--;
                    return f->second;
                }
            }
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */