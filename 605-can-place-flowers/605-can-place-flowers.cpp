class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int m) {
        int k=0,i=-1,j=0,n=fl.size();
        vector<int>a;
        while(j<n && i<=j){
            if(fl[j]==1){
                i=j;
            }else{
                while(j<n && fl[j]==0){
                    j++;
                }
                if(j!=n)
                j--;
                if(i==-1){
                    i--;
                }
                a.push_back(j-i);
            }
            j++;
        }
        for(const auto &x:a){
            if(x%2){
                k+=x/2;
            }else{
                k+=(x-1)/2;
            }
        }
        return k>=m;
    }
};