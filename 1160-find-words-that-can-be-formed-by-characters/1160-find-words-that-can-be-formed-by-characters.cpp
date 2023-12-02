class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        map<int,int>m,m1;
        for(auto x:chars){m[x]++;}
        for(auto y:words){
            m1.clear();
            int f=0;
            for(auto z:y){
                m1[z]++;
                if(m1[z]>m[z]){
                    f=1;
                    break;
                }
            }
            if(!f){ans+=y.length();}
        }
        return ans;
    }
};