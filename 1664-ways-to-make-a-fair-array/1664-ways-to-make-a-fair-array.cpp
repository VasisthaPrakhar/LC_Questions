class Solution {
public:
    int waysToMakeFair(vector<int>& a) {
        int n=a.size();
        if(n==1){return 1;}
        if(n==2){return 0;}
        long long osum=0,esum=0,co=0,ce=a[0],sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                esum+=a[i];
            }else{
                osum+=a[i];
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(i%2==0){
                ce=ce+a[i];
                sum2=esum + co-ce;
                sum1=osum+ce-co-a[i];
            }else{
                co+=a[i];
                sum1=osum+ce-co;
                sum2=esum+co-a[i]-ce;
            }
            if(sum1==sum2){
                ans++;
            }
        }
        if(osum==esum-a[0]){ans++;}
        return ans;
    }
};