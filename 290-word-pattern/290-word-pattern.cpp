class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        stringstream ss(s);
        string temp;
        while(getline(ss,temp,' ')){
            v.push_back(temp);
        }
        if(pattern.length()!=v.size()){
            return false;
        }else{
            unordered_map<char,int>m;
            unordered_map<string,int>m1;
            for(int i=0;i<v.size();i++){
                if(m[pattern[i]]!=m1[v[i]]){
                    return false;
                }
                m[pattern[i]]=i+1;
                m1[v[i]]=i+1;
            }
        }
        return true;
    }
};