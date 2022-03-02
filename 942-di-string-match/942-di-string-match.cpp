class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>a;
        for(int i=0;i<=n;i++){
            a.push_back(i);
        }
        for(int i=0;i<n;i++){
            int k=i,h=i;
            while(s[k]=='D'){
                k++;
            }
            //cout<<k<<" ";
            for(int j=k;j>=h;j--){
                a[i++]=j;
            }
            i--;
        }
        return a;
    }
};