class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int n=c.size();
        vector<int>dif(n);
        for(int i=0;i<n;i++){
            dif[i]=c[i]-r[i];
        }
        sort(dif.begin(),dif.end());
        int j=0,ans=0;
        while(j<n && a>0){
            if(dif[j]<=a){
                a=a-dif[j];
                ans++;
            }else{
                break;
            }
            j++;
        }
        return ans;
    }
};