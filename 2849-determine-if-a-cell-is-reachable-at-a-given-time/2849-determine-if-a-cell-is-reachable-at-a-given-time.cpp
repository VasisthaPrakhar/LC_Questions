class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int ma = abs(fx-sx)+abs(fy-sy);
        if(ma==0 && t-ma==1){
            return 0;
        }
        if(t>=max(abs(fx-sx),abs(fy-sy))){
            return true;
        }
        //&& t<=)
        return false;
    }
};