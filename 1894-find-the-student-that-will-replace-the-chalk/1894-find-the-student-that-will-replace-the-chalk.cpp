class Solution {
public:
    typedef long long int ll;
    int chalkReplacer(vector<int>& c, int k) {
        int n=c.size();
        ll sum=accumulate(c.begin(),c.end(),0LL);
        k=k%sum;
        for(int i=0;i<n;i++){
            if(c[i]>k){
                return i;
            }else{
                k-=c[i];
            }
        }
        return -1;
    }
};