class Solution {
public:
    bool ok(map<char,int>&m1,map<char,int>&m){
    if(m1.size()!=m.size()){
        return false;
    }
    for(auto x:m1){
        if(m[x.first]>x.second){
            return false;
        }
    }
    return true;
}
string minWindow(string a, string b) {
    map<char,int>m,m1;
    for(auto x:b){
        m[x]++;
    }
    int n=a.length();
    if(n<b.length()){
        return "";
    }
    int i=0,j=0,mi=INT_MAX,st;
    while(j<n){
        if(m.count(a[j])){
            m1[a[j]]++;
        }
        //cout<<j<<" ";
        while(ok(m1,m) && i<=j){
            if(mi>j-i+1){
                mi=j-i+1;
                st=i;
            }
            if(m1.count(a[i]) && m1[a[i]]<=m[a[i]]){
                break;
            }
            if(m1.count(a[i])){
                m1[a[i]]--;
            }
            i++;
        }
        j++;  
    }
    return mi==INT_MAX?"":a.substr(st,mi);
    }
};