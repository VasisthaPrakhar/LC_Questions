class Solution {
public:
    int romanToInt(string num) {
    map<char,int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    map<string,int>m1;
    m1["IV"]=4;
    m1["IX"]=9;
    m1["XL"]=40;
    m1["XC"]=90;
    m1["CD"]=400;
    m1["CM"]=900;
    int ans=0,n=num.length();
    for(int i=0;i<n;i++){
        if(i<n-1){
            string temp;
            temp.push_back(num[i]);
            temp.push_back(num[i+1]);
            if(m1.find(temp)!=m1.end()){
                ans+=m1[temp];
                i++;
                continue;
            }
        }
        ans+=m[num[i]];
    }
    return ans;
    }
};