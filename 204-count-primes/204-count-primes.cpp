class Solution {
public:
    int countPrimes(int n) {
        vector<bool>v(n+1,true);
        v[0]=false;
        v[1]=false;
        for(int i=2;i<sqrt(n);i++){
            if(v[i]){
                for(int j=i*i;j<n;j+=i){
                    v[j]=false;
                }
            }
        }
        return count(v.begin(),v.begin()+n,true);
    }
};