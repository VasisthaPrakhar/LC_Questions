class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        set<int>s;
        for(auto x:m){
            s.insert(x.second);
        }
        return (int)s.size()==(int)m.size();
    }
};