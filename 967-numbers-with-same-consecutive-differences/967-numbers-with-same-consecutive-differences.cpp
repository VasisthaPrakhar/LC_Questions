class Solution {
public:
    vector<int>ans;
    void fun(int n,int k,string &s){
        if(s.length()==n){
            ans.push_back(stoi(s));
            return;
        }
        if(s.length()==0){
            for(int i=1;i<=9;i++){
                char ch='0'+i;
                s.push_back(ch);
                fun(n,k,s);
                s.pop_back();
            }
        }else{
            char ch=s.back();
            int a=ch-'0';
            int b=a-k,c=a+k;
            if(b>=0){
                char g=b+'0';
                s.push_back(g);
                fun(n,k,s);
                s.pop_back();
            }
            if(c<=9 && k!=0){
                char g=c+'0';
                s.push_back(g);
                fun(n,k,s);
                s.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s="";
        fun(n,k,s);
        return ans;
    }
};