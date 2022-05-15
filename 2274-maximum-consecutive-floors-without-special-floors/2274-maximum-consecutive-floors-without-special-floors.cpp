class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        sort(s.begin(),s.end());
        int ma=0,n=s.size();
        for(int i=1;i<n;i++){
            ma=max(ma,s[i]-s[i-1]-1);
        }
        ma=max(ma,s[0]-bottom);
        ma=max(ma,top-s[n-1]);
        return ma;
    }
};