class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto &x:details){
            string t="";
            t.push_back(x[11]);
            t.push_back(x[12]);
            if(stoi(t)>60){
                ans++;
            }
        }
        return ans;
    }
};