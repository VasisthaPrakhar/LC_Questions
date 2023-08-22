class Solution {
public:
    string convertToTitle(int num) {
        string ans="";
        while(num){
            int k=(num%26)-1;
            if(num>0 && num%26==0){
                num--;
                k=25;
            }
            ans.push_back(k+'A');
            num/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};