class Solution {
public:
    int fun(vector<int>&a ,int n){
        vector<int>pre(n,0),suf(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
                pre[i]=-1;
            }else{
                pre[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){s.pop();}
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
                suf[i]=n;
            }else{
                suf[i]=s.top();
            }
            s.push(i);
        }
        // for(auto x:suf){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(suf[i]-pre[i]-1)*a[i]);
            // cout<<suf[i]<<" "<<pre[i]<<endl;
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0){
            return 0;
        }
        int m=mat[0].size();
        if(n==1 && m==1){
            return mat[0][0]-'0';
        }
        int ans=0;
        vector<int>a(m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0'){
                    a[j]=0;
                }else{
                    a[j]++;
                }
                //cout<<a[j]<<" ";
            }
            //cout<<endl;
            ans=max(ans,fun(a,m));
        }
        
        return ans;
    }
};