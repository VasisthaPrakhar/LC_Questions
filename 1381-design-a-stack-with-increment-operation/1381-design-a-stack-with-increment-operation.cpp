class CustomStack {
private:
    vector<int>a;
    int n;
public:
    CustomStack(int ma) {
        n=ma;
    }
    
    void push(int x) {
        if(a.size()<n){
            a.push_back(x);
        }
    }
    
    int pop() {
        if(a.size()==0){
            return -1;
        }else{
            int k=a.back();
            a.pop_back();
            return k;
        }
    }
    
    void increment(int k, int val) {
        for(int i=0;i< min(k,(int)a.size());i++){
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */