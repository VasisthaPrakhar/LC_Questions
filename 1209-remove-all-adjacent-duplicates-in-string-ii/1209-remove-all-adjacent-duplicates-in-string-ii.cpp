class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({s[i],0});
            }else{
                if(st.top().first==s[i]){
                    st.push({s[i],st.top().second+1});   
                }else{
                    st.push({s[i],0});
                }
                if(st.top().second==k-1){
                    for(int i=0;i<k;i++){
                        st.pop();
                    }
                }
            }
        }
        string ans="";
        while(st.size()){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};