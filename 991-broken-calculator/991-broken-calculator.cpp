class Solution {
public:
    int brokenCalc(int s, int t) {
        if(s==t){
            return 0;
        }
        int ans=0;
        while(s<t){
            ans++;
            if(t%2){
                t++;
            }
            else
                t=t/2;
        }
        return ans+abs(s-t);
    }
};