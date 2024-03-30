class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n=p.size();
        vector<int>prev(n,0),suf(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(p[i]==0){
                sum-=1;
            }else{
                sum+=1;
            }
            prev[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            suf[i]=sum;
            if(p[i]==0){
                sum-=1;
            }else{
                sum+=1;
            }
        }
        for(int i=0;i<n-1;i++){
            if(prev[i]>suf[i]){
                return i+1;
            }
        }
        return -1;
    }
};