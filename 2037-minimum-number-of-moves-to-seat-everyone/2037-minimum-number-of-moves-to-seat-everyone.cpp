class Solution {
public:
    int minMovesToSeat(vector<int>& s, vector<int>& st) {
        int n=s.size(),sum=0;
        sort(s.begin(),s.end());
        sort(st.begin(),st.end());
        for(int i=0;i<n;i++){
            sum+=abs(s[i]-st[i]);
        }
        return sum;
    }
};