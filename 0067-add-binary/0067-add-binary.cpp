class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int car=0;
        int i=a.length()-2,j=b.length()-2;
        if(i<j){
            while(i<j){
                a='0'+a;
                i++;
            }
        }else{
            while(i>j){
                b='0'+b;
                j++;
            }
        }
        //cout<<a<<" "<<b;
        if(a[i+1]=='1' && b[i+1]=='1'){
            car=1;
            ans.push_back('0');
        }else if(a[i+1]=='1' || b[i+1]=='1'){
            ans.push_back('1');
        }else{
            ans.push_back('0');
        }
        
        while(i>=0 && j>=0){
            if((a[i]=='1' && b[i]=='1' && car==0) || ((a[i]=='1' ^ b[i]=='1') && car==1)){
                car=1;
                ans.push_back('0');
            }
            else if(a[i]=='1' && b[i]=='1' && car==1){
                car=1;
                ans.push_back('1');
            }
            else if((a[i]=='1' ^ b[i]=='1') && car==0){
                ans.push_back('1');
            }
            else if(a[i]=='0' && b[i]=='0' && car==1){
                car=0;
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }
            i--;
            j--;
        }
        if(car){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};