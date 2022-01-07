class RLEIterator {
public:
    long long k=0;
    map<long long,long long>s;
    RLEIterator(vector<int>& e) {
        s[e[0]]=e[1];
        long long sum=e[0];
        for(int i=2;i<e.size();i=i+2){
            if(e[i]>0){
                sum=sum+e[i];
                s[sum]=e[i+1];   
            }
        }
    }
    
    int next(int n) {
        k+=n;
        auto it = s.lower_bound(k);
        if(it==s.end()){
            return -1;
        }
        else{
            return it->second;
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */