class Solution {
public:
   int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string> s(w.begin(),w.end());
        if(s.find(e)==s.end())return 0;
        int ans=1;
        queue<string>q;
        q.push(b);
        while(!q.empty()){
            int k=q.size();
                while(k>0){
                    string n=q.front();
                    if(n==e){
                        return ans;
                    }
                    q.pop();
                    s.erase(n);
                    for(int i=0;i<n.length();i++){
                        char temp=n[i];
                        for(int j=0;j<26;j++){
                            n[i]=j+'a';
                            if(s.find(n)!=s.end()){
                                q.push(n);
                            }
                        }
                        n[i]=temp;
                    }
                    k--;
                }
            ans++;
        }
        return 0;
    }
};