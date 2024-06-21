class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int n=c.size();
        int s=0,s1=0,ma=0,l=-1,r=-1,res=0;
        for(int i=0;i<m;i++){
            s+=c[i];
            if(g[i]==0){
                s1+=c[i];
            }
        }
        if((s-s1)>ma){
            ma=(s-s1),res=s;
            l=0,r=m-1;
        }
        int j=m,i=0;
        while(j<n){
            if(g[j]==0){
                s1+=c[j];
            }
            if(g[i]==0){s1-=c[i];}
            s+=c[j],s-=c[i];
            //cout<<s<<" "<<s1;
            if((s-s1)>ma){
                res=s;
                ma=(s-s1);
                l=i+1,r=j;
            }
            j++,i++;
        }
        //cout<<l<<" "<<r<<" "<<res<<endl;
        for(int i=0;i<l;i++){
            if(g[i]==0){res+=c[i];}
        }
        for(int i=r+1;i<n;i++){
            if(g[i]==0){res+=c[i];}
        }
        return res;
    }
};