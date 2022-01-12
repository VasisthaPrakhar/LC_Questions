class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(27,0);
        vector<bool>visited(27,true);
        for(auto x: s){
            freq[x-'a']++;
            visited[x-'a']=false;
        }
        int f=0;
        string ans=" ";
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a']==false){
                if(f==1){
                    while(s[i]<ans[ans.length()-1] && freq[ans[ans.length()-1]-'a']>0){
                        visited[ans[ans.length()-1]-'a']=false;
                        ans.pop_back();
                    }
                }
                ans=ans+s[i];
                visited[s[i]-'a']=true;
                f=1;
                //cout<<ans<<" ";
            }
        }
        return ans.substr(1,ans.length());
    }
};