class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        stack<char>st;
        for(auto x:s){
            if(x=='['){
                st.push('[');
            }else if(x==']' && (!st.empty() && st.top()=='[')){
                st.pop();
            }else{
                continue;
            }
        }
        double k=st.size();
        return ceil(k/2);
    }
};