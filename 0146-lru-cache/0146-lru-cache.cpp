

class LRUCache {
private:
    list<int>l1;
    unordered_map<int,pair<int,list<int>::iterator>>s;
    int n;
public:
    LRUCache(int capacity) {
        n=capacity;
    }
    int get(int key) {
        if(s.find(key)!=s.end()){
            l1.splice(l1.begin(),l1,s[key].second);
            return s[key].first;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(s.find(key)!=s.end()){
            l1.splice(l1.begin(),l1,s[key].second);
            s[key].first=value;
        }else{
            l1.push_front(key);
            s[key]={value,l1.begin()};
        }
        if(s.size()>n){
            auto a=l1.back();
            l1.pop_back();
            s.erase(a);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */