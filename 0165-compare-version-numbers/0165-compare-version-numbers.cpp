class Solution {
public:
    int fun(string &v1, string &v2){
        int n=v1.length();
        int m=v2.length();
        string a="";
        int i,j;
        for( i=0,j=0;i<n;i++){
            if(v1[i]>='0'){
                a.push_back(v1[i]);
            }
            if(v1[i]=='.'){
                string b="";
                for(;j<m;j++){
                    if(v2[j]=='.'){
                        j++;
                        break;
                    }
                    if(v2[j]>='0'){
                        b.push_back(v2[j]);
                    }
                }
                if(a.size()==0){a.push_back('0');}
                if(b.size()==0){b.push_back('0');}
                long long int c=stoll(a);
                long long int d=stoll(b);
                if(c<d){
                    return -1;
                }
                if(c>d){
                    return 1;
                }
                a="";
            }
        }
        string b="";
        for(;j<m;j++){
            if(v2[j]=='.'){
                j++;
                break;
            }
            if(v2[j]>='0'){
                b.push_back(v2[j]);
            }
        }
        if(a.size()==0){a.push_back('0');}
        if(b.size()==0){b.push_back('0');}
        long long int c=stoll(a);
        long long int d=stoll(b);
        if(c<d){
            return -1;
        }
        if(c>d){
            return 1;
        }
        return 0;
    }
    int compareVersion(string &v1, string &v2) {
        if(fun(v1,v2)==0){
            if(fun(v2,v1)==-1){
                return 1;
            }else if(fun(v2,v1)==1){
                return -1;
            }else{
                return 0;
            }
        }else{
            return fun(v1,v2);
        }
    }
};