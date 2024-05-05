class Solution {
public:
    int minAnagramLength(string s) {
        int n=s.length();
        vector<int>mp(26,0),mp1(26,0);
        for(auto &x:s){
            mp[x-'a']++;
        }
        for(int i=0;i<n;i++){
            mp1[s[i]-'a']++;
            int f=0;
            set<int>t;
            for(int j=0;j<26;j++){
                if(mp[j]>0 && mp1[j]==0){
                    f=1;
                    break;
                }
                if(mp[j]==0 && mp1[j]==0){continue;}
                if(mp[j]%mp1[j]!=0){
                    f=1;
                    break;
                }
                t.insert(mp[j]/mp1[j]);
            }
            if(f==1 || t.size()>1){
                continue;
            }else{
                break;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=mp1[i];
        }
        return ans;
    }
};