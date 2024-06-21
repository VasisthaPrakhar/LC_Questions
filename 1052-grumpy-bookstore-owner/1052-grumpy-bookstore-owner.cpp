class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int n=c.size();
        int s=0,s1=0;
        for(int i=0;i<m;i++){
            s+=c[i];
            if(g[i]==0){
                s1+=c[i];
            }
        }
        int j=m,i=0,l=0,r=m-1,res=s,ma=s-s1;
        while(j<n){
            if(g[j]==0){
                s1+=c[j];
            }
            if(g[i]==0){s1-=c[i];}
            s+=c[j],s-=c[i];
            if((s-s1)>ma){
                res=s;
                ma=(s-s1);
                l=i+1,r=j;
            }
            j++,i++;
        }
        for(int i=0;i<l;i++){
            if(g[i]==0){res+=c[i];}
        }
        for(int i=r+1;i<n;i++){
            if(g[i]==0){res+=c[i];}
        }
        return res;
    }
};