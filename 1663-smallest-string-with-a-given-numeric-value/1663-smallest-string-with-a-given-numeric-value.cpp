class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while(n){
            int t=26;
            while(k-t<n-1){
                t--;
            }
            ans.push_back(t-1+'a');
            k=k-t;
            if(n-1==k){
                n--;
                break;
            }
            n--;
        }
        while(n--){
            ans.push_back('a');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};