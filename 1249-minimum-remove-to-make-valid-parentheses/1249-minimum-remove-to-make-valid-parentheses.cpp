class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first=='(' && s[i]==')'){
                st.pop();
            }else if(s[i]==')' || s[i]=='('){
                st.push({s[i],i});
            }
        }
        set<int>idx;
        while(!st.empty()){
            idx.insert(st.top().second);
            st.pop();
        }
        string ans;
        for(int i=0;i<n;i++){
            if(idx.find(i)==idx.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};