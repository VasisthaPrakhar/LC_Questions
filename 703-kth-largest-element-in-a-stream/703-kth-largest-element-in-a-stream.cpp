class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>p;
    int m;
    KthLargest(int k, vector<int>& nums) {
        for(auto x:nums){
            p.push(x);
        }
        m=k;              
    }
    
    int add(int val) {
        p.push(val);
        while(p.size()>m){
            p.pop();
        }        
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */