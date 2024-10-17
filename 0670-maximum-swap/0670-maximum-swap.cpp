class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        map<int, int> m;
        int n = s.size()-1;
        m[n]=n;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]>s[n]){n=i;}
            m[i]=n;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]<s[m[i]]){
                swap(s[i],s[m[i]]);
                break;
            }
        }
        int no = stoi(s);
        return no;
    }
};