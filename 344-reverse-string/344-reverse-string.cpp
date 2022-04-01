class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0,j=n-1;
        while(j>i){
            swap(s[j--],s[i++]);
        }
    }
};