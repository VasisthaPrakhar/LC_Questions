class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size()-1,c=0;;
        vector<int>ans;
        while(n>=0 && k){
            int r=k%10;
            ans.push_back((r+num[n]+c)%10);
            c=(r+num[n]+c)/10;
            k/=10;
            n--;
        }
        while(n>=0){
            ans.push_back((num[n]+c)%10);
            c=(num[n]+c)/10;
            n--;
        }
        while(k){
            int r=k%10;
            ans.push_back((r+c)%10);
            c=(r+c)/10;
            k/=10;
        }
        if(c){
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};