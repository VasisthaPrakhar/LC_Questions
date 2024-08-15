class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a[2]={0,0};
        for(auto &x:bills){
            if(x==5){
                a[0]++;
            }else if(x==10){
                if(a[0]<1){
                    return false;
                }
                a[0]--;
                a[1]++;
            }else{
                if(a[1]>0){
                    if(a[0]<1){
                        return false;
                    }
                    a[0]--,a[1]--;
                }else{
                    if(a[0]<3){
                        return false;
                    }
                    a[0]-=3;
                }
            }
        }
        return true;
    }
};