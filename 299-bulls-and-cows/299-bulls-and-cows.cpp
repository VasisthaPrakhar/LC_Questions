class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        int n=secret.size();
        unordered_map<char,int>m;
        for(auto x:secret){
            m[x]++;
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i]){
                a++;
                m[secret[i]]--;
                if(m[secret[i]]==0){
                    m.erase(secret[i]);
                }
                guess[i]='a',secret[i]='a';
            }
        }
        for(int i=0;i<n;i++){
            if(guess[i]!=secret[i]){
                if(m.find(guess[i])!=m.end()){
                    b++;
                    m[guess[i]]--;
                    if(m[guess[i]]==0){
                        m.erase(guess[i]);
                    }
                }
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};