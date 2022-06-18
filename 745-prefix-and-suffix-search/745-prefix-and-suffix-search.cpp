class WordFilter {
    private: unordered_map<string,map<string,int>>m;
public:
    WordFilter(vector<string>& w) {
        for(int j=0;j<w.size();j++){
            string x=w[j];
            string temp="";
            int n=x.length();
            for(int i=0;i<n;i++){
                temp+=x[i];
                string t="";
                int n1=n-1;
                while(n1!=-1){
                    t=x[n1]+t;
                    m[temp][t]=j;
                    n1--;
                }
            }
        }
    }
    
    int f(string pre, string suf) {
        if(!m.count(pre)){
            return -1;
        }else{
            if(!m[pre].count(suf)){
                return -1;
            }else{
                return m[pre][suf];
            }
        }
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */