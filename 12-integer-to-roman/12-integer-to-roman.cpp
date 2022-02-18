class Solution {
public:
    string fun(map<int,string>&m, int a){
        if(a==0){
            return "";
        }
        if(m.find(a)!=m.end()){
            return m[a];
        }
        auto it=m.lower_bound(a);
        it--;
        return it->second+fun(m,a-it->first);
    }
    string intToRoman(int num) {
        map<int,string>m;
        m[1]="I";
        m[5]="V";
        m[10]="X";
        m[50]="L";
        m[100]="C";
        m[500]="D";
        m[1000]="M";
        m[4]="IV";
        m[9]="IX";
        m[40]="XL";
        m[90]="XC";
        m[400]="CD";
        m[900]="CM";
        string ans="";
        int n1=num/10,n2=n1/10,n3=n2/10;
        ans=fun(m,(n3%10)*1000)+fun(m,(n2%10)*100)+fun(m,(n1%10)*10)+fun(m,num%10);
        return ans;
    }
};