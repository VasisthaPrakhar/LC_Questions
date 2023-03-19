class WordDictionary {
    private: unordered_map<int,vector<string>>m;
public:
    WordDictionary() {
        m.clear();
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    
    bool search(string w) {
        int n=w.length();
        for(auto &x:m[n]){
            int f=0;
            for(int i=n-1;i>=0;i--){
                if(w[i]=='.'){
                    continue;
                }
                if(x[i]!=w[i]){
                    f=1;
                    break;
                }
            }
            if(!f)
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */