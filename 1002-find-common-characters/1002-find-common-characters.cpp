class Solution {
public:
    vector<string> commonChars(vector<string>& w) {
        int n=w.size();
        vector<int>a(26,INT_MAX);
        for(auto &x:w){
            vector<int>b(26,0);
            for(auto &y:x){
                b[y-'a']++;
            }
            for(int i=0;i<26;i++){
                a[i]=min(b[i],a[i]);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            if(a[i]!=INT_MAX){
                for(int j=0;j<a[i];j++){
                    string t;
                    t.push_back(i+'a');
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};