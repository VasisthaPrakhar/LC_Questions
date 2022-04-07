class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        int n=l.size();
        auto f=upper_bound(l.begin(),l.end(),t)-l.begin();
        if(f==n){
            return l[0]; 
        }
        return l[f];
    }
};