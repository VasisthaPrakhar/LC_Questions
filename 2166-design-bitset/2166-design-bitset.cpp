/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */



class Bitset {
    private: int c=0,n=0,f=0;
    string s;
public:
    Bitset(int size) {
        n=size;
        c=0,f=0;
        string temp(size,'0');
        s=temp;
    }
    
    void fix(int idx) {
        if(f%2){
           if(s[idx]=='1'){
                c++;
            }
            s[idx]='0';
        }else{
            if(s[idx]=='0'){
                c++;
            }
            s[idx]='1';
        }
    }
    
    void unfix(int idx) {
        if(f%2){
           if(s[idx]=='0'){
                c--;
            }
            s[idx]='1';
        }else{
            if(s[idx]=='1'){
                c--;
            }
            s[idx]='0';
        }
    }
    
    void flip() {
        c=n-c;
        f++;
    }
    
    bool all() {
        if(n-c==0){
            return true;
        }
        return false;
    }
    
    bool one() {
        if(n-c<=n-1){
            return true;
        }
        return false;
    }
    
    int count() {
        return c;
    }
    
    string toString() {
        string ans=s;
        if(f%2){
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    ans[i]='1';
                }else{
                    ans[i]='0';
                }
            }
        }        
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */