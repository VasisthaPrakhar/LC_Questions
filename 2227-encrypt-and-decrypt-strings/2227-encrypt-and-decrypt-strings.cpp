#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Encrypter {
    private:unordered_map<char,string>m1;
    unordered_map<string,int>m2;
public:
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& dict) {
        for(int i=0;i<k.size();i++){
            m1[k[i]]=v[i];
        }
        for(auto x:dict){
            string s="";
            for(auto y:x){
                s+=m1[y];
            }
            m2[s]++;
        }
    }
    string encrypt(string word1) {
        string s="";
        for(auto x:word1){
            s+=m1[x];
        }
        return s;
    }
    int decrypt(string word2) {
        return m2[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */