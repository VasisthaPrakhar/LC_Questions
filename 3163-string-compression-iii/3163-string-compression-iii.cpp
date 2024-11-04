class Solution {
public:
    string compressedString(string &w) {
        int n=w.length();
        int c=0,j=0;
        string ans="";
        for(int i=0;i<n;i++){
            j=i,c=0;
            while(i<n && w[j]==w[i] && c<9){
                i++,c++;
            }
            i--;
            ans+=to_string(c);
            ans.push_back(w[i]);
        }
        return ans;
    }
};