class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double n=c.size();
        double s=-1,s1=0;
        for(int i=0;i<n;i++){
            if(s==-1){
                s=c[i][0]+c[i][1];
                s1=s-c[i][0];
            }else{
                if(s>c[i][0]){
                    s+=c[i][1];
                }else{
                    s=c[i][0]+c[i][1];
                }
                s1+=s-c[i][0];
            }
        }
        return s1/n;
    }
};