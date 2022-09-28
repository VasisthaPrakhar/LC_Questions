class Solution {
public:
    string pushDominoes(string d) {
        int n=d.length();
        int i=0,j=0,l=-1,r=-1;
        while(j<n){
           // cout<<j<<" ";
            if(d[j]=='L'){
                if(r==-1){
                    if(l!=-1){
                        i=l;
                    }
                    while(i<j){
                        d[i]='L';
                        i++;
                    }
                }else{
                    int p=r;
                    int q=j;
                    //cout<<p<<" "<<q;
                    while(p<q){
                        d[p]='R';
                        d[q]='L';
                        p++;
                        q--;
                    }
                    r=-1;
                }
                l=j;
            }else if(d[j]=='R'){
                if(r!=-1){
                    i=r;
                    while(i<j){
                        d[i++]='R';
                    }
                }
                r=j;
            }
            j++;
        }
        while(r<n && r!=-1){
            d[r]='R';
            r++;
        }
        return d;
    }
};