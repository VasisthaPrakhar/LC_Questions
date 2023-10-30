class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int &a, int &b)->bool{
            // int c=0,c1=0;
            // for(int i=0;i<15;i++){
            //     if(a & (1<<i)){
            //         c++;
            //     }
            //     if(b& (1<<i)){
            //         c1++;
            //     }
            // }
            int c=__builtin_popcount(a),c1=__builtin_popcount(b);
            if(c==c1){
                return a<b;
            }
            return c<c1;
        });
        return arr;
    }
};