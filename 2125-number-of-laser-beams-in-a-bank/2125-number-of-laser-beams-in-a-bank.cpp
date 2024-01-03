class Solution {
public:
    int count(string s){
        int ans=0;
        for(auto x:s){
            if(x=='1'){
                ans++;
            }
        }
        return ans;
    }
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>a;
        for(int i=0;i<n;i++){
            int k=count(bank[i]);
            if(k){
                a.push_back(k);
            }
        }
        int ans=0;
        if(a.size()>1){
            for(int i=1;i<a.size();i++){
                ans+=a[i-1]*a[i];
            }
            return ans;
        }
        return ans;
    }
};