class RangeFreqQuery {
private:
    unordered_map<int,vector<int>>a;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            a[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(a.count(value)){
            auto f=upper_bound(a[value].begin(),a[value].end(),right);
            auto f1=lower_bound(a[value].begin(),a[value].end(),left);
            return f-f1;
        }
        return 0;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */