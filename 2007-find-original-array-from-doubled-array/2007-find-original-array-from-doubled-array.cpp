class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        int n=c.size();
        if(n%2){
            return {};
        }
        unordered_map<int,int>m;
        vector<int>ans;
        sort(c.begin(),c.end());
        for(auto x:c){
            if(x%2==0 && m.find(x/2)!=m.end()){
                m[x/2]--;
                if(m[x/2]==0){
                    m.erase(x/2);
                }
                ans.push_back(x/2);
                if(ans.size()==n/2){
                    break;
                }
            }else{
                m[x]++;;
            }
        }
        if(ans.size()==n/2)
            return ans;
        return {};
    }
};