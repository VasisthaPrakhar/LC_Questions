class Solution {
public:
    int compareVersion(string v1, string v2) {
        int c=0;
        stringstream ss(v1),ss1(v2);
        string token,token1;
        while(getline(ss,token,'.') && getline(ss1,token1,'.')){
            long long int a=stoll(token),b=stoll(token1);
            if(a<b){
                return -1;
            }else if(a>b){
                return 1;
            }
            c++;
        }
        //ss.clear(),ss1.clear();
        //token="",token1="";
        stringstream ss2(v1),ss3(v2);
        while(c--){
            getline(ss2,token,'.');
            getline(ss3,token1,'.');
        }
       // cout<<token<<" "<<token1<<" ";
        while(getline(ss2,token,'.')){
            long long int a=stoll(token);
            //cout<<"test";
            if(a>0){
                return 1;
            }
        }
        while(getline(ss3,token1,'.')){
            long long int a=stoll(token1);
            if(a>0){
                return -1;
            }
        }
        return 0;
    }
};