class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        long long int n=dif.size(),sum=0,mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=dif[i];
            ma=sum>ma?sum:ma;
            mi=sum<mi?sum:mi;
        }
        int k;
        if(mi>=0){
            k=lower;
        }else{
            k=lower+abs(mi);
        }
        int ans=0;
        while(k>=lower && k<=upper && k+ma>=lower && k+ma<=upper){
            ans++;
            k++;
        }
        return ans;
    }
};