class Solution {
public:
    int minimumRounds(vector<int>& ta) {
        map<int,int>m;
        for(auto x:ta){
            m[x]++;
        }
        int ans=0;
        for(auto x:m){
            if(x.second==1){
                return -1;
            }
            ans+=x.second/3;
            int k=x.second%3;
            if(k>0){
                ans++;
            }
        }
        return ans;
    }
};