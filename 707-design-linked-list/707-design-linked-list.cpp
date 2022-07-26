class MyLinkedList {
    private:
    list<int>l1;
public:
    MyLinkedList() {
        l1.clear();
    }
    
    int get(int index) {
        if(index>=l1.size()){
            return -1;
        }
        auto it=l1.begin();
        advance(it,index);
        return *it;
    }
    
    void addAtHead(int val) {
        l1.push_front(val);
    }
    
    void addAtTail(int val) {
        l1.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index <= l1.size()){
            auto it=l1.begin();
            advance(it,index);
            l1.insert(it,val);
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<l1.size()){
            auto it=l1.begin();
            advance(it,index);
            l1.erase(it);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */