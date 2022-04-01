class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>pre(n,0),ans(n);
        pre[0]=code[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+code[i];
        }
        for(int i=0;i<n;i++){
            if(k>0){
                if(i+k<=n-1){
                    ans[i]=pre[i+k]-pre[i];
                }else{
                    ans[i]=pre[n-1]-pre[i] + (pre[(i+k)-(n-1)]-code[(i+k)-(n-1)]);
                }
            }
            else if(k<0){
                k=abs(k);
                if(i-k<0){
                    ans[i]=pre[i]-code[i] +(pre[n-1]-pre[n-1-abs(i-k)]);
                }else{
                    ans[i]=pre[i]-pre[i-k]-code[i]+code[i-k];
                }
                k=-1*k;
            }else{
                ans[i]=0;
            }
        }
        return ans;
    }
};