class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int m=order.length();
        vector<char>a(26);
        for(int i=0;i<m;i++){
            a[order[i]-'a']='a'+i;
        }
        int n=words.size();
        for(int i=0;i<n;i++){
            for(auto &x:words[i]){
                x=a[x-'a'];
            }
        }
        vector<string>w=words;
        sort(w.begin(),w.end());
        return w==words;
    }
};