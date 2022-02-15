class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        unordered_map<char,int>m1,temp;
        for(int i=0;i<words2.size();i++){
            for(auto x:words2[i]){
                temp[x]++;
            }
            for(auto x:words2[i]){
                if(!m1.count(x)){
                    m1[x]++;
                }else{
                    m1[x]=max(m1[x],temp[x]);
                }
            }
            temp.clear();
        }
        for(int i=0;i<words1.size();i++){
            for(auto x:words1[i]){
                temp[x]++;
            }
            int f=0;
            for(auto x:m1){
                if(!temp.count(x.first) || temp[x.first]<x.second){
                    f=1;
                    break;
                }
            }
            if(!f){
                ans.push_back(words1[i]);
            }
            temp.clear();
        }
        return ans;
    }
};