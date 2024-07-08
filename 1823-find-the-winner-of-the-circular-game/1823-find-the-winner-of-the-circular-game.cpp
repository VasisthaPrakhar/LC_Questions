class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>a;
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        int sz=a.size(),st=0;
        while(sz>1){
            int q=((k-1)%sz);
            while(q>0){
                if(a[st]!=-1){
                    q--;
                }
                st=(st+1)%n;
            }
            //cout<<q<<" "<<st<<endl;
            while(a[st]==-1){
                st=(st+1)%n;
            }
            a[st]=-1;
            st=(st+1)%n,sz--;
        }
        for(int i=0;i<n;i++){
            if(a[i]>0){
                return a[i];
            }      
        }
        return 0;
    }
};