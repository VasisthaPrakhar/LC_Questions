class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& w) {
        int n=w.size();
        unordered_map<int,int>m;
        for(auto &x:w){
            for(auto &y:x){
                m[y]++;
            }
        }
        int ev=0,od=0;
        for(auto &x:m){
            if(x.second%2){
                ev+=x.second-1;
                od++;
            }else{
                ev+=x.second;
            }
        }
        sort(w.begin(),w.end(),[](string &a,string &b)->bool{
            return a.length()<b.length();
        });
        int ans=0,k=0;
        for(auto &x:w){
            int l=x.length();
            if(l%2){
                if(ev+od>=l){
                    if(ev>=l-1 && od>0){
                        ev-=(l-1);
                        od--;
                        ans++;
                    }else if(ev>=l && od==0){
                        ev-=l;
                        ans++;
                    }
                }else if(l==1){
                    if(od>0){
                        od++;
                    }else{
                        k++;
                    }
                }
            }else{
                if(ev>=l){
                    ev-=l;
                    ans++;
                }
            }
        }
        if(k>0){
            if(ev+od>0){
                ans+=min(k,od+ev);
            }
        }
        //cout<<ev<<" "<<od<<endl;
        return ans;
    }
};