class Solution {
public:
     string fun(int n)
    {
        string s;
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                s.push_back('1');
            else
                s.push_back('0');
        }
        return s;
    }
    int fun2(int start, int goal) {
        string s=fun(start);
        string t=fun(goal);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                ans++;
            }
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        return fun2(start,goal);
    }
};