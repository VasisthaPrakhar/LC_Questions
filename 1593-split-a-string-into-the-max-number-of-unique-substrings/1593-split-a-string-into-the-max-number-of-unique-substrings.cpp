class Solution {
public:
    
    void sol(vector<string>v,string s,int idx,set<string> se,int *ans){
        if(idx==s.length())
        {
            if(v.size()>*ans)
            {
                *ans=v.size();
            }
            return ;
        }
        string temp="";
        for(int i=idx;i<s.length();i++)
        {
            temp.push_back(s[i]);
            if(se.find(temp)==se.end())
            {
                v.push_back(temp);
                se.insert(temp);
                sol(v,s,i+1,se,ans);
                v.pop_back();
                se.erase(temp);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        vector<string>v;
        set<string>se;
        int ans=0;
    
        sol(v,s,0,se,&ans);
        return ans;
    }
};