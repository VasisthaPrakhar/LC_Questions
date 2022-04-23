class Solution {
public:
    double angleClock(int h, int m) {
        double am=m*6;
        double a=((double)m/60.0)*30.0;
        double ah=h*30.0+a;
        double ans=0;
        if(ah<am){
            ans=min(360.0-(am-ah),am-ah);
        }else{
            ans=min(360.0-(ah-am),ah-am);
        }
        return ans;
    }
};