class Solution {
public:
    int fun(vector<int>&a){
        int n=a.size();
        stack<int>s,s1;
        vector<int>pre(n),suf(n);//pre to get index of min element in left and suf to get index of min element in right
        for(int i=0;i<n;i++){
            while(!s1.empty() && a[s1.top()]>=a[i]){s1.pop();}
            if(s1.empty()){pre[i]=-1;}
            else{
                pre[i]=s1.top();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]>=a[i]){s.pop();}
            if(s.empty()){suf[i]=n;}
            else{
                suf[i]=s.top();
            }
            s.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,(suf[i]-pre[i]-1)*a[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0){
            return 0;
        }
        int m=mat[0].size();
        if(m==1 && n==1){
            return mat[0][0]-'0';
        }
        int ans=INT_MIN;
        vector<int>a(m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0'){
                    a[j]=0;
                }else{
                    a[j]++;
                }
            }
            // for(auto x:a){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            ans=max(ans,fun(a));
        }
        return ans;
    }
};