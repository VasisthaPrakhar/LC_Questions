class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        ios_base::sync_with_stdio(0) , cin.tie(NULL);
        int n=seats.size();
        vector<int>beg(n,INT_MAX),end(n,INT_MAX);
        int j=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                j=i;
            }
            else if(j!=-1){
                beg[i]=i-j;
            }
        }
        j=-1;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                j=i;
            }
            else if(j!=-1){
                end[i]=j-i;
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            int mi=min(beg[i],end[i]);
            if(mi!=INT_MAX)
            res=max(res,mi);
        }
        return res;
    }
};