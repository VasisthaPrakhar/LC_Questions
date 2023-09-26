class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int>a(26,0),vis(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        string ans="";
        ans+=s[0];
        a[s[0]-'a']--;
        vis[s[0]-'a']=1;
        for(int i=1;i<n;i++){
            a[s[i]-'a']--;
            if(!vis[s[i]-'a']){
                while(ans.size() && s[i]<ans.back() && a[ans.back()-'a']>0){
                    vis[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans+=s[i];
                vis[s[i]-'a']=1;
            }
        }
        return ans;
    }
};