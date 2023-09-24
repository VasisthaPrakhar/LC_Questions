class Solution {
private: vector<vector<double>> init(double p,int qr){
    vector<vector<double>>a(102,vector<double>(102,0));
    a[0][0]=p;
    for(int i=0;i<qr+1;i++){
        for(int j=0;j<=i;j++){
            if(a[i][j]>1){
                a[i+1][j]+=(a[i][j]-1)/2.0;
                a[i+1][j+1]+=(a[i][j]-1)/2.0;
                a[i][j]=1;
            }
        }
    }
    return a;
}
public:
    double champagneTower(int p, int qr, int qc) {
        vector<vector<double>>a=init(p,qr);
        return a[qr][qc];
    }
};