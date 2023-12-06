class Solution {
public:
    int totalMoney(int n) {
       int k=(n/7),r=n%7,z=0,l=k+1;
        while(r){
            z+=l;
            r--,l++;
        };
        //cout<<(k*(2*28 + ((k-1)*7))/2);
        return (k*(2*28 + ((k-1)*7))/2) + z;
    }
};