class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        int m=t.size();
        vector<string>ans;
        for(int i=1,j=0;i<=n && j<m;i++){
            if(t[j]==i){
                ans.push_back("Push");
                j++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};