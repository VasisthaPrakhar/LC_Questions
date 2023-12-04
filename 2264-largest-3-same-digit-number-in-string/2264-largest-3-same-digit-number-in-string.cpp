class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        map<int,int>v;
        for(int i=0;i<3;i++){
            v[num[i]-'0']++;
        }
        int ans=-1;
        int j=3;
        if(v.size()==1){
            int a=v.begin()->first;
            ans=max(ans,a*100+a*10+a);
        }
        while(j<n){
            v[num[j]-'0']++;
            v[num[j-3]-'0']--;
            if(v[num[j-3]-'0']==0){
                v.erase(num[j-3]-'0');
            }
            if(v.size()==1){
                int a=v.begin()->first;
                ans=max(ans,a*100+a*10+a);
            }
            j++;
        }
        if(ans==-1){
            return "";
        }else if(ans==0){
            return "000";
        }
        return to_string(ans);
    }
};