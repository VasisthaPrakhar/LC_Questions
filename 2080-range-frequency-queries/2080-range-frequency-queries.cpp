class RangeFreqQuery {
    private: unordered_map<int,vector<int>>m;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(m.count(value)){
            auto y=lower_bound(m[value].begin(),m[value].end(),left);
            auto z=upper_bound(m[value].begin(),m[value].end(),right);
            return z-y;
        }
        return 0;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
