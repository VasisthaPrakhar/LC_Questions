class Solution {
public:
    typedef long long int ll;
    bool fun(int n, int k, int budget, vector<vector<int>>& co, vector<int>& stock, vector<int>& cost,ll mid){
         for(int i=0;i<k;i++){
            long double s=0;
            for(int j=0;j<n;j++){
                ll req=mid*co[i][j]-stock[j];
                if(req>0)
                    s+=req*cost[j];    
            }
            if(s<=budget){
                return true;
            }
         }
        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& co, vector<int>& stock, vector<int>& cost) {
        ll beg=0,end=1e10,ans=0,mid=0,f=1;
        while(beg<=end){
            //cout<<beg<<" "<<end<<endl;
            mid=(beg+end)/2;
            if(fun(n,k,budget,co,stock,cost,mid)){
                //cout<<mid<<" ";
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
            
        }
        return ans;
    }
};