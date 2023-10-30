class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int &a, int &b)->bool{
            int c=0,c1=0;
            for(int i=0;i<16;i++){
                if(a & (1<<i)){
                    c++;
                }
                if(b& (1<<i)){
                    c1++;
                }
            }
            if(c==c1){
                return a<b;
            }
            return c<c1;
        });
        return arr;
    }
};