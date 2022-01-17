class Solution {
public:
    int mySqrt(int x) {
        int no=46340;
        vector<long long int> v(no);
        for(int i=0;i<no;i++){
            v[i]=(i+1)*(i+1);
        }
        int k=0;
        for(int i=v.size()-1;i>=0;i--){
            if(x>=v[i]){
                k=i+1;
                break;
            }
        }
        return k;
    }
};