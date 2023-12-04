class Solution {
public:
    string largestGoodInteger(string &num) {
        int n=num.length();
        map<int,int>v;
        for(int i=0;i<3;i++){
            v[num[i]-'0']++;
        }
        int ans=-1;
        int j=3;
        if(v.size()==1){
            int a=v.begin()->first;
            ans=max(ans,a*100+a*10+a);
        }
        while(j<n){
            v[num[j]-'0']++;
            v[num[j-3]-'0']--;
            if(v[num[j-3]-'0']==0){
                v.erase(num[j-3]-'0');
            }
            if(v.size()==1){
                int a=v.begin()->first;
                ans=max(ans,a*100+a*10+a);
            }
            j++;
        }
        if(ans==-1){
            return "";
        }else if(ans==0){
            return "000";
        }
        return to_string(ans);
    }
};
// class Solution {
// public:
//     bool check(string &s,map<int,int>&m){
//         for(auto x:s){
//             m[x]++;
//         }
//         return m.size()==1;
//     }
//     string largestGoodInteger(string &num) {
//         string ans="";
//         int n=num.length();
//         map<int,int>m;
//         for(int i=0;i<n-2;i++){
//             m.clear();
//             string temp=num.substr(i,3);
//             if(check(temp,m)){
//                 ans=max(ans,temp);
//             }
//         }
//         return ans;
//     }
// };