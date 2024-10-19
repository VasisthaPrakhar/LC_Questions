class Solution {
public:
    void fun(int n, int k, vector<int>&a,int &z,int &x){
        if(n==1){
            return;
        }
        int sz=a[n-1];
        int mid=((sz+1)/2);
        if(k==mid){
            x=1;
            return;
        }else if(k<mid){
            fun(n-1,k,a,z,x);
        }else{
            z++;
            fun(n-1,(sz-k+1),a,z,x);
        }
    }
    char findKthBit(int n, int k) {
        int c=1;
        vector<int>a;
        for(int i=0;i<=20;i++){
            a.push_back(c);
            c=(2*c)+1;
        }
        int z=0,x=0;
        fun(n,k,a,z,x);
        if(z%2){
            if(x==0){
                return '1';
            }else{
                return '0';
            }
        }else{
            return '0'+x;
        }
        for(auto x:a){
            cout<<x<<" ";
        }
        return '0';
    }
};