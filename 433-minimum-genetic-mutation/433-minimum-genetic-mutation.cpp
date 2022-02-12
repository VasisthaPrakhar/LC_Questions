class Solution {
public:
    int minMutation(string b, string e, vector<string>& w) {
        if(b==e){return 0;}
         unordered_set<string> s(w.begin(),w.end());
        if(s.find(e)==s.end())return -1;
        int ans=0;
        queue<string>q;
        q.push(b);
        char d[4]={'A','C','G','T'};
        if(s.find(b)!=s.end()){
            s.erase(b);
        }
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
                        for(int j=0;j<4;j++){
                            n[i]=d[j];
                            if(s.find(n)!=s.end()){
                                q.push(n);
                                s.erase(n);
                            }
                        }
                        n[i]=temp;
                    }
                    k--;
                }
            ans++;
        }
        return -1;
    }
};