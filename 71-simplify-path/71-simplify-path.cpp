class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        stack<string>s;
        int j=0;
        while(j<n){
            if(path[j]!='/'){
                string temp;
                while(j<n && path[j]!='/'){
                    temp.push_back(path[j]);
                    j++;
                }
                if(temp=="."){}
                else if(temp==".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }else{
                    s.push(temp);
                }
            }
            j++;
        }
        string ans="";
        while(!s.empty()){
            ans=s.top()+"/"+ans;
            s.pop();
        }
        if(ans.size())
        ans.pop_back();
        ans="/"+ans;
        return ans;
    }
};