class Solution {
public:
    int myAtoi(string s) {
          int i,k=1;
        long long ans=0;
        for(i=0;s[i]==' ';i++){}
            if(s[i]=='-'){
                k=-1;
                i++;
            }
            else if(s[i]=='+'){
                k=1;
                i++;
            }
            for(int j=i;j<s.length()&&(s[j]>=48)&&(s[j]<=57);j++)
            {
                ans=(ans*10)+(s[j]-'0');
                if(ans>INT_MAX && k>0)
                    return INT_MAX;
                if(ans>INT_MAX && k<0)
                    return INT_MIN;
            }
        return ans*k;
    }
};