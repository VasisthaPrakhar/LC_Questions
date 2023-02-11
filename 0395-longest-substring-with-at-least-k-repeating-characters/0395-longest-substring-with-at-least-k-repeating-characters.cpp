class Solution {
public:
    int longestSubstring(string s, int k) {
        // int n=s.length();
        // if(k>n){
        //     return 0;
        // }
        // unordered_map<char,int>m;
        // int ans=0,i=0;
        // for(int i=0;i<n;i++){
        //     m[s[i]]++;
        // }
        // while(i<n && m[s[i]]>=k){
        //     i++;
        // }
        // if(i==n){
        //     return n;
        // }
        // int l=longestSubstring(s.substr(0,i),k);
        // while(i<n && m[s[i]]<k) 
        //     i++;
        // int r=longestSubstring(s.substr(i),k);
        // ans=max(l,r);
        // return ans;
        int n=s.length();
        int ans=0;
        unordered_map<char,int>m;
        for(int sz=1;sz<27;sz++){
            m.clear();
            int j=0,i=0,p=0;
            while(j<n){
                m[s[j]]++;
                if(m[s[j]]==k){
                    p++;
                }
                while(i<j && m.size()>sz){
                    m[s[i]]--;
                    if(m[s[i]]==k-1){
                        p--;
                    }
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                if(p==sz && m.size()==sz){
                    // cout<<j<<" "<<i<<" "<<k<<endl;
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};