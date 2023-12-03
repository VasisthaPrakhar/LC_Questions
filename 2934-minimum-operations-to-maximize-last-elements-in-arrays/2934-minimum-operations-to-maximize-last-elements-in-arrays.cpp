class Solution {
public:
    int fun(int &x,int &y,int &n,vector<int>& a, vector<int>& b){
        set<int>s;
        int f=0;
        //cout<<x<<" "<<y<<endl;
        for(int i=0;i<n;i++){
            if(a[i]>x){
                if(b[i]<=x){
                    s.insert(i);
                }else{
                    f=1;
                    break;
                }
            }
            if(b[i]>y){
                if(a[i]<=y){
                    s.insert(i);
                }else{
                    f=1;
                    break;
                }
            }
        }
        if(f){return -1;}
        return s.size();
    }
    int minOperations(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int lma=a[n-1],lmb=b[n-1];
        int ma=*max_element(a.begin(),a.end());
        int mb=*max_element(b.begin(),b.end());
        if(max(ma,mb)>max(lma,lmb)){
            return -1;
        }
        int x=fun(lma,lmb,n,a,b);
        int y=fun(lmb,lma,n,a,b);
        //cout<<endl;
        if(x==-1 && y==-1){
            return -1;
        }else if(x==-1){
            return y;
        }else if(y==-1){
            return x;
        }else{
            return min(x,y);
        }
        
    }
};