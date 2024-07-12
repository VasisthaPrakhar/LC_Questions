class Solution {
public:
    int maximumGain(string &s, int x, int y) {
        int n=s.length(),ans=0;
        stack<char>st;
        int f=0;
        for(int i=0;i<n;i++){
            if(x>y){
                if(s[i]=='b' && !st.empty() && st.top()=='a'){
                    st.pop();
                    ans+=x;
                    f=1;
                }else{
                    st.push(s[i]);
                }
            }else{
                if(s[i]=='a' && !st.empty() && st.top()=='b'){
                    st.pop();
                    ans+=y;
                    f=1;
                }else{
                    st.push(s[i]);
                }
            }
        }
        //cout<<st.size()<<endl;
        if(f==0){
            while(!st.empty()){
                st.pop();
            }
            for(int i=0;i<n;i++){
                if(x>y){
                    if(s[i]=='a' && !st.empty() && st.top()=='b'){
                        st.pop();
                        ans+=y;
                        f=1;
                    }else{
                        st.push(s[i]);
                    }
                }else{
                    if(s[i]=='b' && !st.empty() && st.top()=='a'){
                        st.pop();
                        ans+=x;
                        f=1;
                    }else{
                        st.push(s[i]);
                    }
                }
            }
        }
        string t;
        while(!st.empty()){
            t.push_back(st.top());
            st.pop();
        }
        reverse(t.begin(),t.end());
        if(f)
            return ans+maximumGain(t,x,y);
        return ans;
    }
};