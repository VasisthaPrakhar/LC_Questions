class Solution {
public:
    string s_sum(string s,string t){
        int n=s.length()-1,m=t.length()-1;
        int car=0;
        string ans="";
        while(n>=0 && m>=0){
            int k=(s[n]-'0')+(t[m]-'0')+car;
            car=k/10;
            ans=to_string(k%10)+ans;
            n--,m--;
        }
        while(n>=0){
            int k=(s[n]-'0')+car;
            car=k/10;
            ans=to_string(k%10)+ans;
            n--;
        }
        while(m>=0){
            int k=(t[m]-'0')+car;
            car=k/10;
            ans=to_string(k%10)+ans;
            m--;
        }
        if(car){
            ans=to_string(car)+ans;
        }
        return ans;
    }
    bool fun(string p1,string p2,int n, int idx, string num,int f){
        if(idx==n){
            if(f>=3){
                return true;
            }
            return false;
        }
        //cout<<p1<<" "<< p2<< " "<<num[idx]<<endl;
        bool ans=false;
        if(p1=="-1" && p2=="-1"){
            for(int i=1;i<n;i++){
                string s=num.substr(idx,i);
                if(s[0]=='0'&& s.length()>1){continue;}
                ans|=fun(s,p2,n,i,num,f+1);
            }
        }else if(p2=="-1"){
            for(int i=1;i<n-idx;i++){
                string s=num.substr(idx,i);
                if(s[0]=='0' && s.length()>1){continue;}
                ans|=fun(p1,s,n,idx+i,num,f+1);
            }
        }else{
            //cout<<p1<<" "<< p2<< " "<<num[idx]<<endl;
            string s=s_sum(p1,p2);
            int i=0,m=s.length();
            while(i<m){
                if(idx>=n){
                    return false;
                }
                if(s[i]!=num[idx]){
                    return false;
                }
                i++,idx++;
            }
            ans|=fun(p2,s,n,idx,num,f+1);
        }
        return ans;
    }
    bool isAdditiveNumber(string num) {
        int n=num.length();
        return fun("-1","-1",n,0,num,0);
    }
};