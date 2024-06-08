class segment_tree{
private:
    int n;
    vector<int>seg;
    void build_seg_tree(int idx,int start,int end ,vector<int>&a){
        if(start==end){
            seg[idx]=a[start];
            return;
        }
        int mid=(start+end)>>1;
        build_seg_tree(2*idx+1,start,mid,a);
        build_seg_tree(2*idx+2,mid+1,end,a);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int query(int idx,int start, int end,int l,int r){
        if(end<l || start>r){
            return 0;
        }
        if(end<=r && start>=l){
            return seg[idx];
        }
        int mid=(start+end)>>1;
        int left = query(2*idx+1,start,mid,l,r);
        int right = query(2*idx+2,mid+1,end,l,r);
        return left+right;
    }

    void update(int idx,int start, int end,int i,int val){
        if(start==end){
            seg[idx]=val;
            return;
        }
        int mid=(start+end)>>1;
        if(i<=mid)
            update(2*idx+1,start,mid,i,val);
        else
            update(2*idx+2,mid+1,end,i,val);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

public:
    segment_tree(vector<int>&a){
        this->n=a.size();
        this->seg.resize(4* (this->n),INT_MAX);
        build_seg_tree(0,0,(this->n)-1,a);
    }
    int range_query(int l,int r){
        return query(0,0, (this->n)-1,l,r);
    }
    void update_query(int idx,int val){
        update(0,0, (this->n)-1,idx,val);
    }
};

class NumArray {
private:
    segment_tree *Tree=NULL;
public:
    NumArray(vector<int>& nums) {
        Tree=new segment_tree(nums);
    }
    
    void update(int index, int val) {
        Tree->update_query(index,val);
    }
    
    int sumRange(int left, int right) {
        return Tree->range_query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */