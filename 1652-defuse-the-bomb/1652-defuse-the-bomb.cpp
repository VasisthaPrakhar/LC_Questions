class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        int n=a.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(k>0){
                int z=k,j=i,s=0;
                while(z>0){
                    j=((j+1)+n)%n;
                    s+=a[j];
                    z--;
                }
                //cout<<s<<endl;
                ans[i]=s;
            }else if(k<0){
                int z=abs(k),j=i,s=0;
                while(z>0){
                    j=((j-1)+n)%n,z--;
                    s+=a[j];
                }
                ans[i]=s;
            }else{
                ans[i]=0;
            }
        }
        return ans;
    }
};