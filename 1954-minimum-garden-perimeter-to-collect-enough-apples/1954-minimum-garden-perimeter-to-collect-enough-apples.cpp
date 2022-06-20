class Solution {
public:
    long long minimumPerimeter(long long ne) {
        long long cnt=0,ans=0;
        while(ans<ne){
            cnt+=1;
            ans+=12*(cnt*cnt);
        }
        return 4*(2*cnt);
    }
};