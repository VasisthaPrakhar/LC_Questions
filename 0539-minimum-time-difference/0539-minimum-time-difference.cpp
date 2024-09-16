class Solution {
public:
    int findMinDifference(vector<string>& t) {
        int n=t.size();
        set<int>s;
        for(auto x:t){
            string h=x.substr(0,2);
            string m=x.substr(3,2);
            int hh=stoi(h),mm=stoi(m);
            int k=hh*60 + mm;
            if(s.find(k)==s.end()){
                s.insert(k);
                s.insert(k+1440);
            }else{
                return 0;
            }
        }
        vector<int>a;
        for(auto x:s){a.push_back(x);};
        int sz=a.size(),ans=INT_MAX;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                ans=min(ans,abs(a[j]-a[i]));
            }
        }
        return ans;
    }
};