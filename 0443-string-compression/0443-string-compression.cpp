class Solution {
public:
    int compress(vector<char>& chars) {
        string ans="";
        for(int i=0;i<chars.size();i++){
            char s = chars[i];
            ans.push_back(s);
            int c=0;
            while(i<chars.size() && chars[i]==s){
                c++;
                i++;
            }
            i--;
            if(c>1){
                string ch = to_string(c);
                ans+=ch;
            }
        }
        for(int i=0;i<ans.size();i++){
            chars[i] = ans[i];
        }
        return ans.length();
    }
};