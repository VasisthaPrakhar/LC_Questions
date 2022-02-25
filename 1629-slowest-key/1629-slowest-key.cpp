class Solution {
public:
    char slowestKey(vector<int>& r, string& s) {
        int ma=-1,prev=0,idx;
        int n=r.size();
        for(int i=0;i<n;i++){
            if(ma<=r[i]-prev){
                idx=ma==r[i]-prev?(s[idx]>s[i]?idx:i):i;
                ma=r[i]-prev;
            }
            prev=r[i];
        }
        return s[idx];
    }
};