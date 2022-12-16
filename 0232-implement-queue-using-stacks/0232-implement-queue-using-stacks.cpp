class MyQueue {
private: stack<int>s,s1;
public:
    MyQueue() {
        while(!s.empty()){
            s.pop();
        }
        while(!s1.empty()){
            s1.pop();
        }
    }
    
    void push(int x) {
        while(!s1.empty()){
            s.push(s1.top());
            s1.pop();
        }
        s.push(x);
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
    }
    
    int pop() {
        int k=s1.top(); 
        s1.pop();
        return k;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */