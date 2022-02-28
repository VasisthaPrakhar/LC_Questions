class Solution {
public:
    int openLock(vector<string>& d, string target) {
        unordered_set<string>s(d.begin(),d.end());
        if(s.count("0000")){
            return -1;
        }
        queue<string>q;
        int ans=0;
        q.push("0000");
        s.insert("0000");
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node==target){
                    return ans;
                }
                for(int i=0;i<4;i++){
                    string temp=node;
                    temp[i]=(temp[i]-'0'+1+10)%10+'0';
                    if(!s.count(temp)){
                        s.insert(temp);
                        q.push(temp);
                    }
                    temp=node;
                    temp[i]=(temp[i]-'0'-1+10)%10+'0';
                    if(!s.count(temp)){
                        s.insert(temp);
                        q.push(temp);
                    }
                }
                
            }
            ans++;
        }
        return -1;
    }
};