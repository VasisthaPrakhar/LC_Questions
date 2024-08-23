class Solution {
public:
    typedef long long int ll;
    int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    ll findlcm(vector<int>&arr, int n){
        ll ans = arr[0];
        for (int i = 1; i < n; i++)
            ans = (((arr[i] * ans)) /
                    (gcd(arr[i], ans)));

        return ans;
    }
    string fractionAddition(string e) {
        int n=e.length();
        vector<int>sign,num,den;
        if(isdigit(e[0])){
            sign.push_back(1);
        }
        for(int i=0;i<n;i++){
            string s="";
            if(isdigit(e[i])){
                while(isdigit(e[i])){
                    s.push_back(e[i]);
                    i++;
                }
                num.push_back((stoi(s)));
                if(e[i]=='/'){
                    i++;
                }
                s="";
                while(isdigit(e[i])){
                    s.push_back(e[i]);
                    i++;
                }
                i--;
                den.push_back((stoi(s)));
            }else{
                if(e[i]=='-')
                    sign.push_back(0);
                else
                    sign.push_back(1);
            }
        }
        ll d=findlcm(den,den.size());
        ll nu=0;
        for(int i=0;i<num.size();i++){
            int k=d/den[i],s=1;
            if(sign[i]==0){
                s=-1;
            }
            nu+=k*s*num[i];
        }
        int k=abs(gcd(nu,d));
        string ans=to_string(nu/k) + "/" + to_string(d/k);
        //cout<<nu/k<<"/"<<d/k<<endl;
        return ans;
    }
};