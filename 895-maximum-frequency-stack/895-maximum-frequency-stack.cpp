class FreqStack {
    private:
    unordered_map<int,int>m;
    priority_queue<pair<int,pair<int,int>>>pq;
    int idx=0;
public:
    FreqStack() {
        m.clear();
        while(!pq.empty()){
            pq.pop();
        }
        
    }
    
    void push(int val) {
        m[val]++;
        pq.push({m[val],{idx++,val}});
    }
    
    int pop() {
        int t=pq.top().second.second;
        pq.pop();
        m[t]--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */