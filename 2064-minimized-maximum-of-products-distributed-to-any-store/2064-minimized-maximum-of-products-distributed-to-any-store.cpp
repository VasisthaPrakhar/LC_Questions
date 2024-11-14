class Solution {
public:
    bool check(int mid,int n,int k,vector<int>&a){
        int c=0;
        for(int i=0;i<n;i++){
            c+=ceil((double)a[i]/(double)mid);
        }
        return c<=k;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int m=q.size();
        int ma=*max_element(q.begin(),q.end());
        if(n==m){
            return ma;
        }
        int beg=1,end=ma,mid;
        while(beg<end){
            mid=(beg+end)/2;
            //cout<<beg<<" "<<end<<" "<<mid<<endl;
            if(check(mid,m,n,q)){
                end=mid;
            }else{
                beg=mid+1;
            }
        }
        return end;
    }
};