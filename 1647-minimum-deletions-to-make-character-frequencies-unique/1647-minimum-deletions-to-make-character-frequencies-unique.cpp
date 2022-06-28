class Solution {
public:
    int minDeletions(string s) {
        vector<int>m(26,0);
        for(auto x:s){
            m[x-'a']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(m[i]>0)
                pq.push(m[i]);
        }
        int ans=0,prev=-1;
        while(!pq.empty()){
            int k=pq.top();
            if(prev==pq.top()){
                if(k>1)
                    pq.push(k-1);
                ans++;
            }
            pq.pop();
            prev=k;
        }
        return ans;
    }
};