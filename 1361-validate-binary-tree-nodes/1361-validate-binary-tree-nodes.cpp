class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        queue<int>q;
        vector<int>vis(n,0);
        set<int>s;
        int c=-1;
        for(int i=0;i<n;i++){
            if(l[i]!=-1)
                s.insert(l[i]);
            if(r[i]!=-1){
                s.insert(r[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()){
                if(c==-1){
                    c=i;
                }else{
                    return false;
                }
            }
        }
        if(c==-1){return false;}
        q.push(c);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(vis[top]==1){
                return false;
            }
            if(l[top]!=-1){
                q.push(l[top]);
            }
            if(r[top]!=-1){
                q.push(r[top]);
            }
            vis[top]=1;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    if(vis[top]==1){
                        return false;
                    }
                    if(l[top]!=-1){
                        q.push(l[top]);
                    }
                    if(r[top]!=-1){
                        q.push(r[top]);
                    }
                    vis[top]=1;
                }
            }
        }
        return true;
    }
};