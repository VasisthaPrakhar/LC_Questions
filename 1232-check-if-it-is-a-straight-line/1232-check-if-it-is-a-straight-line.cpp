class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        int n=co.size();
        int x=co[0][0];
        int y=co[0][1];
        double slope=INT_MIN;
        for(int i=1;i<n;i++){
            if(slope==INT_MIN){
                if(x==co[i][0]){
                    slope=INT_MAX;
                }else{
                    slope=(double)(co[i][1]-y)/(double)(co[i][0]-x);
                }
            }else{
                double k=0;
                if(x==co[i][0]){
                    k=INT_MAX;
                }else{
                    k=(double)(co[i][1]-y)/(double)(co[i][0]-x);   
                }
                if(k!=slope){
                    return false;
                }
            }
            cout<<slope<<" ";
            x=co[i][0];
            y=co[i][1];
        }
        return true;
    }
};