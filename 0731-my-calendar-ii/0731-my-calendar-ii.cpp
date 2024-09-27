class MyCalendarTwo {
    map<int,int>mp;
public:
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int c=0;
        for(auto x:mp){
            c+=x.second;
            if(c>=3){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */