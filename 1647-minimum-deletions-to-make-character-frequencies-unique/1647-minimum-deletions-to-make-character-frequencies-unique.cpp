class Solution {
public:
    int minDeletions(string s) {
        map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        priority_queue<int>m1;
        for(auto x:m){
            m1.push(x.second);
        }
        int ans=s.length(),prev=-1;
        while(!m1.empty()){
            int k=m1.top();
            if(prev==m1.top()){
                if(k>1)
                    m1.push(k-1);
                ans--;
            }
            m1.pop();
            //cout<<k<<" ";
            prev=k;
        }
        return s.length()-ans;
    }
};