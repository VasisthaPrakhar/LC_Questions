class Solution {
public:
    bool fun(vector<string>&a,vector<string>&b){
        for(auto x:a){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:b){
            cout<<x<<" ";
        }
        int n=a.size(),m=b.size();
        int i=0,j=n-1,x=0,y=m-1;
        while(i<=j){
            int f=0;
            if(a[i]==b[x]){
                i++,x++,f++;
            }
            if(a[j]==b[y]){
                j--,y--,f++;
            }
            if(f==0){
                return false;
            }
        }
        return true;
    }
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss(s1);
        stringstream ss1(s2);
        vector<string>a,b;
        string t;
        while(getline(ss,t,' ')){
            //transform(t.begin(), t.end(), t.begin(), ::tolower);
            a.push_back(t);
        }
        while(getline(ss1,t,' ')){
            //transform(t.begin(), t.end(), t.begin(), ::tolower);
            b.push_back(t);
        }
        int n=a.size(),m=b.size();
        return n<m?fun(a,b):fun(b,a);
    }
};