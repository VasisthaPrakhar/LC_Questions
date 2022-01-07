class RLEIterator {
public:
    long long k=0;
    vector<long long>s;
    vector<long long>s1;
    RLEIterator(vector<int>& e) {
        s.push_back(e[0]);
        s1.push_back(e[1]);
        long long sum=e[0];
        for(int i=2;i<e.size();i=i+2){
            if(e[i]>0){
                sum=sum+e[i];
                s.push_back(sum);
                s1.push_back(e[i+1]);
            }
        }
    }
    
    int next(int n) {
        k+=n;
        auto it = lower_bound(s.begin(),s.end(),k)-s.begin();
        if(it==s.size()){
            return -1;
        }
        else{
            return s1[it];
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */