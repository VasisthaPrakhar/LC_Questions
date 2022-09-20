class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>m;
        for(auto &x:paths){
            vector<string>str;
            string temp;
            stringstream ss(x);
            while(getline(ss,temp,' ')){
                str.push_back(temp);
            }
            //cout<<str[0]<<" ";
            if(str.size()>1){
                for(int i=1;i<str.size();i++){
                    int n=str[i].length();
                    auto z=str[i];
                   // cout<<z<<" ";
                    int k=-1;
                    for(int j=0;j<n;j++){
                        if(z[j]=='('){
                            k=j+1;
                            break;
                        }
                    }
                    if(k!=-1){
                        string a=z.substr(0,k-1);
                        string b=z.substr(k);
                        //cout<<a<<" "<<b<<endl;
                        string res=str[0]+"/"+a;
                        m[b].push_back(res);
                    }
                }
            }
        }
        vector<vector<string>>ans;
        for(auto x:m){
            if(x.second.size()>1){
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};