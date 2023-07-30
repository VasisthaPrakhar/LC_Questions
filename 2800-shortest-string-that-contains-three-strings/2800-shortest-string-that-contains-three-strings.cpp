class Solution {
public:
    string fun1(string &a, string &b){
        int n=a.length();
        int m=b.length();
        vector<int>pos;
        for(int i=0;i<n;i++){
            if(a[i]==b[0]){
                pos.push_back(i);
            }
        }
        for(auto x:pos){
            string temp=a.substr(x);
            auto f=b.find(temp);
            if(f != string::npos && f==0){
                return a.substr(0,x)+b;
            }
        }
        return a+b;
    }
    string fun(string &a, string &b, string &c){
        auto f1=a.find(b);
        string aa="";
        if(f1 != string::npos){
            aa=a;
        }else{
            aa=fun1(a,b);
        }
        //cout<<aa<<endl;
        auto f=aa.find(c);
        if(f != string::npos){
            return aa;
        }
        return fun1(aa,c);
    }
    string mini(vector<string>a){
        int len=a[0].length();
        string ans=a[0];
        for(int i=1;i<a.size();i++){
            if(a[i].length()<len){
                ans=a[i];
                len=a[i].length();
            }else if(a[i].length()==len && a[i]<ans){
                ans=a[i];
                len=a[i].length();
            }
        }
        return ans;
    }
    string minimumString(string &a, string &b, string &c) {
        return mini({fun(a,b,c),fun(a,c,b),fun(b,a,c),fun(b,c,a),fun(c,a,b),fun(c,b,a)});
    }
};