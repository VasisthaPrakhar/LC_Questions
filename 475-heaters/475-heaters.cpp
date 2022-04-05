class Solution {
public:
    int fun(vector<int>& ho, vector<int>& he, int mid){
        int n=ho.size();
        int m=he.size();
        int i=0,j=0;
        while(i<n){
            if(j==m){
                return false;
            }
            int l=he[j]-mid;
            int r=he[j]+mid;
            if(ho[i]>r || ho[i]<l){
                j++;
            }else{i++;}
        }
        return true;
    }
    int findRadius(vector<int>& ho, vector<int>& he) {
        sort(ho.begin(),ho.end());
        sort(he.begin(),he.end());
        int beg=0,end=1e9;
        while(beg<end){
            int mid=(beg+end)>>1;
            if(fun(ho,he,mid)){
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        //cout<<beg<<" "<<end;
        return beg;
    }
};