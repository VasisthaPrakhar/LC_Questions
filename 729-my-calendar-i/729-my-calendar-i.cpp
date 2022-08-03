class MyCalendar {
    private:map<int,int>m;
public:
    MyCalendar() {
        m.clear();
    }
    
    bool book(int start, int end) {
        auto it=m.lower_bound(end);
        if(it==m.begin()){
            m[start]=end;
            return true;
        }
        it--;
        if(start>=it->second){
            m[start]=end;
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */