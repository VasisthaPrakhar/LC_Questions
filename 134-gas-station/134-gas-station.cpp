class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>a(n);
        for(int i=0;i<n;i++){
            a[i]=gas[i]-cost[i];
        }
        int sum=0,ans=0,sum1=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum<0){
                ans=i+1;
                sum1+=sum;
                sum=0;
            }
        }
        if(sum1+sum<0){
            return -1;
        }else{
            return ans;
        }
    }
};