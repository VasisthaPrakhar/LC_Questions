class Solution {
public:
    bool check(vector<int>&a, vector<int>&b){
        for(int i=0;i<60;i++){
            if(a[i]>b[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(s==t){
            return s;
        }
        if(m>n){
            return "";
        }
        vector<int>a(60,0),b(60,0);
        for(auto x:t){
            a[x-'A']++;
        }
        int j=0,sz=INT_MAX,i=0,l=-1;
        while(j<n){
            b[s[j]-'A']++;
            while(check(a,b) && i<=j){
                if(sz>j-i+1){
                    sz=j-i+1;
                    l=i;
                }
                b[s[i]-'A']--;
                i++;
            }
            j++;
        }
        //cout<<l<<" ";
        return l==-1?"":s.substr(l,sz);
    }
};