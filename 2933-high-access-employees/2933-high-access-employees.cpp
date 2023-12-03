class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        map<string,vector<int>>m;
        for(auto &x:at){
            m[x[0]].push_back(stoi(x[1]));
        }
        vector<string>ans;
        for(auto x:m){
            if(x.second.size()>=3){
                int c=0;
                sort(x.second.begin(),x.second.end());
                int n=x.second.size();
                for(int i=1;i<n-1;i++){
                    int d1=x.second[i+1]-x.second[i];
                    if(x.second[i+1]/100 != x.second[i]/100){
                        d1-=40;
                    }
                    int d2=x.second[i]-x.second[i-1];
                    if(x.second[i]/100 != x.second[i-1]/100){
                        d2-=40;
                    }
                    if(d1+d2<60){
                        ans.push_back(x.first);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};