class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp;
        stringstream ss(s);
        while(getline(ss,temp,' ')){
            reverse(temp.begin(),temp.end());
            ans+=temp+" ";
        }
        ans.pop_back();
        return ans;
    }
};