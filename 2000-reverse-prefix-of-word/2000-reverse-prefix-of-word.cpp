class Solution {
public:
    string reversePrefix(string &w, char ch) {
        int n=w.length();
        for(int i=0;i<n;i++){
            if(w[i]==ch){
                reverse(w.begin(),w.begin()+i+1);
                break;
            }
        }
        return w;
    }
};