class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n=s.length();
        double c=0;
        for(auto x:s){
            if(x==letter){
                c++;
            }
        }
        double k=(c/(double)n)*100;
        cout<<k;
        return floor(k);
    }
};