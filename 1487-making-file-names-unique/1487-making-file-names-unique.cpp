class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n=names.size();
        if(n==1){
            return names;
        }
        vector<string>ans;
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            string x=names[i];
            while(m.count(x)){
                int j=m[names[i]];
                x=names[i];
                x+= "(" + to_string(j++) +")";
                m[names[i]]=j;  
            }
            ans.push_back(x);
            m[x]++;
        }
        return ans;
    }
};