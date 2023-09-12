class Solution {
public:
    int minDeletions(string &s) {
        map<char,int>m;
        for(auto &x:s){
            m[x]++;
        }
        priority_queue<int>pq;
        for(auto x:m){
            pq.push(x.second);
        }
        int ans=0,prev=-1;
        while(!pq.empty()){
            int k=pq.top();
            //cout<<k<<" ";
            if(k==prev){
                ans++;
                if(k>1)
                    pq.push(k-1);
            }
            pq.pop();
            prev=k;
        }
        return ans;
    }
};