class Solution {
public:
    int shortestSequence(vector<int>& r, int k) {
        int n=r.size(),ans=1;
       set<int>s;
        for(int i=0;i<n;i++){
            s.insert(r[i]);
            if(s.size()==k){
                s.clear();
                ans++;
            }
        }
        return ans;
    }
};