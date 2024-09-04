class Solution {
public:
    int robotSim(vector<int>& co, vector<vector<int>>& ob) {
        int n=co.size();
        set<vector<int>>s(ob.begin(),ob.end());
        pair<int,int>p={0,0};
        map<pair<char,int>,char>m;
        m[{'N',-1}]='E';
        m[{'N',-2}]='W';
        m[{'S',-1}]='W';
        m[{'S',-2}]='E';
        m[{'W',-1}]='N';
        m[{'W',-2}]='S';
        m[{'E',-1}]='S';
        m[{'E',-2}]='N';
        char dir='N';
        int ans=0;
        for(int i=0;i<n;i++){
            if(co[i]<0){
                dir=m[{dir,co[i]}];
            }else{
                for(int j=0;j<co[i];j++){
                    if(dir=='N'){
                        p.second++;
                        if(s.count({p.first,p.second})){
                            p.second--;
                            break;
                        }
                    }else if(dir=='S'){
                        p.second--;
                        if(s.count({p.first,p.second})){
                            p.second++;
                            break;
                        }
                    }else if(dir=='E'){
                        p.first++;
                        if(s.count({p.first,p.second})){
                            p.first--;
                            break;
                        }
                    }
                    else{
                        p.first--;
                        if(s.count({p.first,p.second})){
                            p.first++;
                            break;
                        }
                    }
                }
            }
            ans=max(ans,(p.first*p.first) + (p.second*p.second));
        }
        return ans;
    }
};