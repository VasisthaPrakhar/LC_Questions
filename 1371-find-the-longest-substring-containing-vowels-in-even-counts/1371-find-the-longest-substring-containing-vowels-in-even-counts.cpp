class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.length();
        map<char,int>mp;
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        vector<int>pre(n+1,0);
        int k=0;
        for(int i=0;i<n;i++){
            pre[i]=k;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                k=k^(1<<mp[s[i]]);
            }
        }
        pre[n]=k;
        map<int,vector<int>>m;
        for(int i=0;i<n+1;i++){
            m[pre[i]].push_back(i);
        }
        int ans=0;
        for(auto x:m){
            cout<< x.first<<":: "<<x.second.back()<<" "<<x.second[0]<<endl;
            ans=max(ans,(x.second.back()-x.second[0]));
        }
        return ans;
    }
};