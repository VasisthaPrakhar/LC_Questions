class Solution {
public:
    bool check(vector<int>&pos,int mid,int m,int n){
        int c=1,p=pos[0];
        for(int i=1;i<n;i++){
            if(pos[i]-p >= mid){
                p=pos[i];
                c++;
            }
            if(c==m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n=pos.size();
        if(m==2){
            return pos[n-1]-pos[0];
        }
        long long int beg=0,end=pos[n-1]-pos[0],ans=0,mid;
        while(beg<=end){
            mid=(beg+end)>>1;
            if(check(pos,mid,m,n)){
                ans=ans>mid?ans:mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};