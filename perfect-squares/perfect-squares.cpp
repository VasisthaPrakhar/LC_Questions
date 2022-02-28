class Solution {
public:
    int numSquares(int n) {
        unordered_set<int>s;
        vector<int>sq;
        int k=1;
        while(k*k<=n){
            sq.push_back(k*k);
            k++;
        }
        queue<int>q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                if(node==n){
                    return ans;
                }
                for(auto x:sq){
                    if(!s.count(node+x) && node+x<=n){
                        s.insert(node+x);
                        q.push(node+x);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};