class Solution {
public:
    vector<int> fun(int n){
        vector<int>a(10,0);
        string s=to_string(n);
        while(s.length()>0){
            a[s.back()-'0']++;
            s.pop_back();
        }
        return a;
    }
    bool reorderedPowerOf2(int n) {
        set<vector<int>>m;
        for(int i=0;i<31;i++){
            int k=1<<i;
            m.insert(fun(k));
        }
        vector<int>a=fun(n);
        if(m.find(a)!=m.end()){
            return true;
        }
        return false;
    }
};