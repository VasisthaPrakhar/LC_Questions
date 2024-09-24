class Solution {
public:
    int fun(int a){
        int c=0;
        while(a){
            c++;
            a/=10;
        }
        return c;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        unordered_set<int>s;
        vector<int>v;
        for(int i=0;i<n;i++){
            while(arr1[i]){
                s.insert(arr1[i]);
                arr1[i]/=10;
            }
        }
        for(int i=0;i<m;i++){
            while(arr2[i]){
                v.push_back(arr2[i]);
                arr2[i]/=10;
            }
        }
        sort(v.begin(),v.end(),[](int a,int b)->bool{
            int c=0,c1=0;
            while(a){
                c++;
                a/=10;
            }
            while(b){
                c1++;
                b/=10;
            }
            return c<c1;
        });
        int sz=v.size();
        for(int i=sz-1;i>=0;i--){
            if(s.find(v[i])!=s.end()){
                return fun(v[i]);
            }
        }
        return 0;
    }
};